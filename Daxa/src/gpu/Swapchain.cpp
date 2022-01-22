#include "Swapchain.hpp"

#include <iostream>
#include <chrono>

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <VkBootstrap.h>

#include "Instance.hpp"

namespace daxa {
	namespace gpu {
		VkSurfaceKHR createSurface(void* sdlWindowHandle, VkInstance instance) {
			VkSurfaceKHR surface;
			SDL_Vulkan_CreateSurface((SDL_Window*)sdlWindowHandle, instance, &surface);
			return surface;
		}

		void Swapchain::construct(VkDevice device, Graveyard* graveyard, VkPhysicalDevice physicalDevice, VkInstance instance, SwapchainCreateInfo ci) {
			this->device = device;
			this->physicalDevice = physicalDevice;
			this->instance = instance;
			this->size = { .width = ci.width, .height = ci.height };
			this->surface = ci.surface;
			this->presentMode = ci.presentMode;
			this->additionalimageUses = ci.additionalUses;
			this->graveyard = graveyard;

			vkb::SwapchainBuilder swapchainBuilder{ physicalDevice, device, surface };

			auto oldSwapchain = swapchain;
			if (swapchain != VK_NULL_HANDLE) {
				swapchainBuilder.set_old_swapchain(swapchain);
			}

			vkb::Swapchain vkbSwapchain = swapchainBuilder
				.use_default_format_selection()
				.set_desired_present_mode(presentMode)
				.set_desired_extent(ci.width, ci.height)
				.add_image_usage_flags(additionalimageUses)
				.build()
				.value();
			
			//store swapchain and its related images
			this->swapchain = vkbSwapchain.swapchain;
			auto vkImages = vkbSwapchain.get_images().value();
			auto vkImageViews = vkbSwapchain.get_image_views().value();
			for (int i = 0; i < vkImages.size(); i++) {
				auto handle = ImageHandle{ std::make_shared<Image>() };
				this->swapchainImages.push_back(std::move(handle));
				auto& img = *this->swapchainImages.back();
				img.extent.width = ci.width;
				img.extent.height = ci.height;
				img.extent.depth = 1;
				img.allocation = nullptr;
				img.allocator = nullptr;
				img.image = vkImages[i];
				img.view = vkImageViews[i];
				img.device = device;
				img.type = VK_IMAGE_TYPE_2D;
				img.viewFormat = vkbSwapchain.image_format;
				img.tiling = VK_IMAGE_TILING_OPTIMAL;
				img.usageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
				img.aspect = VK_IMAGE_ASPECT_COLOR_BIT;
				img.arrayLayers = 1;
				img.mipmapLevels = 1;
				img.graveyard = graveyard;
			}


			this->swapchainImageFormat = vkbSwapchain.image_format;

			if (oldSwapchain) {
				vkDestroySwapchainKHR(device, oldSwapchain, nullptr);
			}

			VkFenceCreateInfo fenceCI{
				.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
				.pNext = nullptr,
				.flags = 0,
			};

			if (aquireFence == VK_NULL_HANDLE) {
				vkCreateFence(device, &fenceCI, nullptr, &this->aquireFence);
			}

			if (daxa::gpu::instance->pfnSetDebugUtilsObjectNameEXT != nullptr && ci.debugName != nullptr) {
				this->debugName = debugName;

				auto nameInfo = VkDebugUtilsObjectNameInfoEXT{
					.sType =  VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
					.pNext = NULL,
					.objectType = VK_OBJECT_TYPE_SWAPCHAIN_KHR,
					.objectHandle = (uint64_t)this->swapchain,
					.pObjectName = ci.debugName,
				};
				daxa::gpu::instance->pfnSetDebugUtilsObjectNameEXT(device, &nameInfo);

				std::string nameBuffer = ci.debugName;
				nameBuffer += " fence";

				nameInfo = VkDebugUtilsObjectNameInfoEXT{
					.sType =  VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
					.pNext = NULL,
					.objectType = VK_OBJECT_TYPE_FENCE,
					.objectHandle = (uint64_t)this->aquireFence,
					.pObjectName = nameBuffer.c_str(),
				};
				daxa::gpu::instance->pfnSetDebugUtilsObjectNameEXT(device, &nameInfo);
				
				for (int i = 0; i < vkImages.size(); i++) {
					nameBuffer.clear();
					nameBuffer = ci.debugName;
					nameBuffer += " image view nr ";
					nameBuffer += std::to_string(i);
					auto view = this->swapchainImages[i]->getVkView();

					nameInfo = VkDebugUtilsObjectNameInfoEXT{
						.sType =  VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
						.pNext = NULL,
						.objectType = VK_OBJECT_TYPE_IMAGE_VIEW,
						.objectHandle = (uint64_t)view,
						.pObjectName = nameBuffer.c_str(),
					};
					daxa::gpu::instance->pfnSetDebugUtilsObjectNameEXT(device, &nameInfo);

					(*this->swapchainImages[i]).debugName = nameBuffer;
				}
			}
		}

		Swapchain::~Swapchain() {
			swapchainImages.clear();
			if (device) {
				vkDestroySwapchainKHR(device, swapchain, nullptr);
				vkDestroyFence(device, aquireFence, nullptr);
				device = VK_NULL_HANDLE;
			}
		}

		SwapchainImage Swapchain::aquireNextImage() {
			u32 index{ 0 };
			auto err = vkAcquireNextImageKHR(device, swapchain, UINT64_MAX, nullptr, aquireFence, &index);
			DAXA_ASSERT_M(err == VK_SUCCESS, "could not aquire next image from swapchain");
			SwapchainImage si{};
			si.swapchain = swapchain;
			si.imageIndex = index;
			si.image = swapchainImages[index];

			vkWaitForFences(device, 1, &aquireFence, VK_TRUE, UINT64_MAX);
			vkResetFences(device, 1, &aquireFence);

			return si;
		}

		void Swapchain::resize(VkExtent2D newSize) {
			swapchainImages.clear();
			construct(device, graveyard, physicalDevice, instance, {surface, newSize.width, newSize.height, presentMode, additionalimageUses, .debugName = debugName.c_str()});
		}

		void Swapchain::setPresentMode(VkPresentModeKHR newPresentMode) {
			swapchainImages.clear();
			construct(device, graveyard, physicalDevice, instance, {surface, size.width, size.height, newPresentMode, additionalimageUses, .debugName = debugName.c_str()});
		}
	}
}
