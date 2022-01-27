#pragma once

#include "../DaxaCore.hpp"

#include <memory>
#include <unordered_map>
#include <optional>

#include <vulkan/vulkan.h>

#include <vk_mem_alloc.h>

#include "Handle.hpp"
#include "Sampler.hpp"
#include "DeviceBackend.hpp"

namespace daxa {
	namespace gpu {
		struct ImageCreateInfo {
			VkImageCreateFlags      flags 		= {};
			VkImageType             imageType 	= VK_IMAGE_TYPE_2D;
			VkFormat                format 		= VK_FORMAT_R8G8B8A8_SRGB;
			VkExtent3D              extent 		= {};
			uint32_t                mipLevels 	= 1;
			uint32_t                arrayLayers = 1;
			VkSampleCountFlagBits   samples 	= VK_SAMPLE_COUNT_1_BIT;
			VkImageTiling           tiling 		= VK_IMAGE_TILING_OPTIMAL;
			VkImageUsageFlags       usage 		= {};
			VmaMemoryUsage 			memoryUsage = VMA_MEMORY_USAGE_GPU_ONLY;
			char const*  			debugName 	= {};
		};

		class Image {
		public:
			Image(std::shared_ptr<DeviceBackend> deviceBackend, ImageCreateInfo const& ci);
			Image() 							= default;
			Image(Image const&) 				= delete;
			Image& operator=(Image const&) 		= delete;
			Image(Image&&) noexcept 			= delete;
			Image& operator=(Image&&) noexcept 	= delete;
			~Image();

			VkImageCreateFlags getVkImageCreateFlags() const { return flags; }
			VkImageType getVkImageType() const { return imageType; }
			VkFormat getVkFormat() const { return format; }
			VkExtent3D getVkExtent3D() const { return extent; }
			u32 getMipLevels() const { return mipLevels; }
			u32 getArrayLayers() const { return arrayLayers; }
			VkSampleCountFlagBits getVkSampleCountFlagBits() const { return samples; }
			VkImageTiling getVkImageTiling() const { return tiling; }
			VkImageUsageFlags getVkImageUsageFlags() const { return usage; }
			VmaMemoryUsage getVmaMemoryUsage() const { return memoryUsage; }
			VkImage getVkImage() const { return image; }
			VmaAllocation getVmaAllocation() const { return allocation; }
			std::string const& getDebugName() const { return debugName; }
		private:
			friend class Device;
			friend class Swapchain;
			friend struct ImageStaticFunctionOverride;

			std::shared_ptr<DeviceBackend> 	deviceBackend 	= {};
			VkImageCreateFlags      		flags 			= {};
			VkImageType             		imageType 		= {};
			VkFormat                		format 			= {};
			VkExtent3D              		extent 			= {};
			uint32_t                		mipLevels 		= {};
			uint32_t                		arrayLayers 	= {};
			VkSampleCountFlagBits   		samples 		= {};
			VkImageTiling           		tiling 			= {};
			VkImageUsageFlags       		usage 			= {};
			VmaMemoryUsage 					memoryUsage 	= {};
			VkImage 						image 			= {};
			VmaAllocation 					allocation 		= {};
			std::string  					debugName 		= {};
		};

		class ImageHandle : public SharedHandle<Image>{};

		struct ImageViewCreateInfo {
			VkImageViewCreateFlags     	flags				= {};
			ImageHandle					image		 		= {};
			VkImageViewType            	viewType			= VK_IMAGE_VIEW_TYPE_2D;
			VkFormat                   	format				= {};
			VkComponentMapping         	components			= {};
			VkImageSubresourceRange    	subresourceRange	= {
				.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
				.baseMipLevel = 0,
				.levelCount = 1,
				.baseArrayLayer = 0,
				.layerCount = 1,
			};
			SamplerHandle				defaultSampler		= {};
			char const* 				debugName			= {};
		};

		class ImageView : public GraveyardRessource {
		public:
			ImageView(std::shared_ptr<DeviceBackend> deviceBackend, ImageViewCreateInfo const& ci);
			ImageView() 								= default;
			ImageView(ImageView const&) 				= delete;
			ImageView& operator=(ImageView const&) 		= delete;
			ImageView(ImageView&&) noexcept 			= delete;
			ImageView& operator=(ImageView&&) noexcept 	= delete;
			virtual ~ImageView();

			VkImageViewCreateFlags getVkImageViewCreateFlags() const { return flags; }
			ImageHandle const& getImageHandle() const { return image; }
			VkImageViewType getVkImageViewType() const { return viewType; }
			VkFormat getVkFormat() const { return format; }
			VkComponentMapping getVkComponentMapping() const { return components; }
			VkImageSubresourceRange getVkImageSubresourceRange() const { return subresourceRange; }
			std::string const& getDebugName() const { return debugName; }
			VkImageView getVkImageView() const { return view; }
			SamplerHandle const& getSampler() const { return defaultSampler; }
			//VkImage getVkImage() const { return  }
		private:
			friend class Device;
			friend class Swapchain;
			friend struct ImageViewStaticFunctionOverride;

			std::shared_ptr<DeviceBackend> 	deviceBackend 		= {};
			VkImageViewCreateFlags     		flags				= {};
			ImageHandle						image		 		= {};
			VkImageViewType            		viewType			= {};
			VkFormat                   		format				= {};
			VkComponentMapping         		components			= {};
			VkImageSubresourceRange    		subresourceRange	= {};
			std::string 					debugName			= {};
			VkImageView						view				= {};
			SamplerHandle 					defaultSampler 		= {};
		};

        struct ImageViewStaticFunctionOverride {
            static void cleanup(std::shared_ptr<ImageView>& value) {
				if (value && value->deviceBackend && value.use_count() == 1) {
					std::unique_lock lock(value->deviceBackend->graveyard.mtx);
					for (auto& zombieList : value->deviceBackend->graveyard.activeZombieLists) {
						zombieList->zombies.push_back(value);
					}
				}
			}
        };

		class ImageViewHandle : public SharedHandle<ImageView, ImageViewStaticFunctionOverride>{};
	}
}