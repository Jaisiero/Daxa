#ifndef __DAXA_TYPES_H__
#define __DAXA_TYPES_H__

#include <vulkan/vulkan.h>
#include <daxa/c/core.h>

typedef enum
{
    DAXA_RESULT_SUCCESS = 0,
    DAXA_RESULT_NOT_READY = 1,
    DAXA_RESULT_TIMEOUT = 2,
    DAXA_RESULT_EVENT_SET = 3,
    DAXA_RESULT_EVENT_RESET = 4,
    DAXA_RESULT_INCOMPLETE = 5,
    DAXA_RESULT_ERROR_OUT_OF_HOST_MEMORY = -1,
    DAXA_RESULT_ERROR_OUT_OF_DEVICE_MEMORY = -2,
    DAXA_RESULT_ERROR_INITIALIZATION_FAILED = -3,
    DAXA_RESULT_ERROR_DEVICE_LOST = -4,
    DAXA_RESULT_ERROR_MEMORY_MAP_FAILED = -5,
    DAXA_RESULT_ERROR_LAYER_NOT_PRESENT = -6,
    DAXA_RESULT_ERROR_EXTENSION_NOT_PRESENT = -7,
    DAXA_RESULT_ERROR_FEATURE_NOT_PRESENT = -8,
    DAXA_RESULT_ERROR_INCOMPATIBLE_DRIVER = -9,
    DAXA_RESULT_ERROR_TOO_MANY_OBJECTS = -10,
    DAXA_RESULT_ERROR_FORMAT_NOT_SUPPORTED = -11,
    DAXA_RESULT_ERROR_FRAGMENTED_POOL = -12,
    DAXA_RESULT_ERROR_UNKNOWN = -13,
    DAXA_RESULT_ERROR_OUT_OF_POOL_MEMORY = -1000069000,
    DAXA_RESULT_ERROR_INVALID_EXTERNAL_HANDLE = -1000072003,
    DAXA_RESULT_ERROR_FRAGMENTATION = -1000161000,
    DAXA_RESULT_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS = -1000257000,
    DAXA_RESULT_PIPELINE_COMPILE_REQUIRED = 1000297000,
    DAXA_RESULT_ERROR_SURFACE_LOST_KHR = -1000000000,
    DAXA_RESULT_ERROR_NATIVE_WINDOW_IN_USE_KHR = -1000000001,
    DAXA_RESULT_SUBOPTIMAL_KHR = 1000001003,
    DAXA_RESULT_ERROR_OUT_OF_DATE_KHR = -1000001004,
    DAXA_RESULT_ERROR_INCOMPATIBLE_DISPLAY_KHR = -1000003001,
    DAXA_RESULT_ERROR_VALIDATION_FAILED_EXT = -1000011001,
    DAXA_RESULT_ERROR_INVALID_SHADER_NV = -1000012000,
    DAXA_RESULT_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR = -1000023000,
    DAXA_RESULT_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR = -1000023001,
    DAXA_RESULT_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR = -1000023002,
    DAXA_RESULT_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR = -1000023003,
    DAXA_RESULT_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR = -1000023004,
    DAXA_RESULT_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR = -1000023005,
    DAXA_RESULT_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT = -1000158000,
    DAXA_RESULT_ERROR_NOT_PERMITTED_KHR = -1000174001,
    DAXA_RESULT_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT = -1000255000,
    DAXA_RESULT_THREAD_IDLE_KHR = 1000268000,
    DAXA_RESULT_THREAD_DONE_KHR = 1000268001,
    DAXA_RESULT_OPERATION_DEFERRED_KHR = 1000268002,
    DAXA_RESULT_OPERATION_NOT_DEFERRED_KHR = 1000268003,
    DAXA_RESULT_MISSING_EXTENSION = (1 << 30) + 0,
    DAXA_RESULT_INVALID_BUFFER_ID = (1 << 30) + 1,
    DAXA_RESULT_INVALID_IMAGE_ID = (1 << 30) + 2,
    DAXA_RESULT_INVALID_IMAGE_VIEW_ID = (1 << 30) + 3,
    DAXA_RESULT_INVALID_SAMPLER_ID = (1 << 30) + 4,
    DAXA_RESULT_BUFFER_DOUBLE_FREE = (1 << 30) + 5,
    DAXA_RESULT_IMAGE_DOUBLE_FREE = (1 << 30) + 6,
    DAXA_RESULT_IMAGE_VIEW_DOUBLE_FREE = (1 << 30) + 7,
    DAXA_RESULT_SAMPLER_DOUBLE_FREE = (1 << 30) + 8,
    DAXA_RESULT_INVALID_BUFFER_INFO = (1 << 30) + 9,
    DAXA_RESULT_INVALID_IMAGE_INFO = (1 << 30) + 10,
    DAXA_RESULT_INVALID_IMAGE_VIEW_INFO = (1 << 30) + 11,
    DAXA_RESULT_INVALID_SAMPLER_INFO = (1 << 30) + 12,
    DAXA_RESULT_COMMAND_LIST_COMPLETED = (1 << 30) + 13,
    DAXA_RESULT_COMMAND_LIST_NOT_COMPLETED = (1 << 30) + 14,
    DAXA_RESULT_INVALID_CLEAR_VALUE = (1 << 30) + 15,
    DAXA_RESULT_BUFFER_NOT_HOST_VISIBLE = (1 << 30) + 16,
    DAXA_RESULT_BUFFER_NOT_DEVICE_VISIBLE = (1 << 30) + 17,
    DAXA_RESULT_INCOMPLETE_COMMAND_LIST = (1 << 30) + 18,
    DAXA_RESULT_DEVICE_DOES_NOT_SUPPORT_BUFFER_COUNT = (1 << 30) + 19,
    DAXA_RESULT_DEVICE_DOES_NOT_SUPPORT_IMAGE_COUNT = (1 << 30) + 20,
    DAXA_RESULT_DEVICE_DOES_NOT_SUPPORT_SAMPLER_COUNT = (1 << 30) + 21,
    DAXA_RESULT_FAILED_TO_CREATE_NULL_BUFFER = (1 << 30) + 22,
    DAXA_RESULT_FAILED_TO_CREATE_NULL_IMAGE = (1 << 30) + 23,
    DAXA_RESULT_FAILED_TO_CREATE_NULL_IMAGE_VIEW = (1 << 30) + 24,
    DAXA_RESULT_FAILED_TO_CREATE_NULL_SAMPLER = (1 << 30) + 25,
    DAXA_RESULT_FAILED_TO_CREATE_BUFFER = (1 << 30) + 26,
    DAXA_RESULT_FAILED_TO_CREATE_IMAGE = (1 << 30) + 27,
    DAXA_RESULT_FAILED_TO_CREATE_IMAGE_VIEW = (1 << 30) + 28,
    DAXA_RESULT_FAILED_TO_CREATE_DEFAULT_IMAGE_VIEW = (1 << 30) + 29,
    DAXA_RESULT_FAILED_TO_CREATE_SAMPLER = (1 << 30) + 30,
    DAXA_RESULT_FAILED_TO_CREATE_BDA_BUFFER = (1 << 30) + 31,
    DAXA_RESULT_FAILED_TO_SUBMIT_DEVICE_INIT_COMMANDS = (1 << 30) + 32,
    DAXA_RESULT_INVALID_BUFFER_RANGE = (1 << 30) + 33,
    DAXA_RESULT_INVALID_BUFFER_OFFSET = (1 << 30) + 34,
    DAXA_RESULT_INVALID_UNIFORM_BUFFER_SLOT = (1 << 30) + 35,
    DAXA_RESULT_MAX_ENUM = 0x7FFFFFFF,
} daxa_Result;

// ImageLayout matches vulkan's image layouts
typedef enum
{
    DAXA_IMAGE_LAYOUT_UNDEFINED = 0,
    DAXA_IMAGE_LAYOUT_GENERAL = 1,
    DAXA_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6,
    DAXA_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL = 7,
    DAXA_IMAGE_LAYOUT_READ_ONLY_OPTIMAL = 1000314000,
    DAXA_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL = 1000314001,
    DAXA_IMAGE_LAYOUT_PRESENT_SRC = 1000001002,
    DAXA_IMAGE_LAYOUT_MAX_ENUM = 0x7FFFFFFF,
} daxa_ImageLayout;

#define _DAXA_DECL_VEC2_TYPE(SCALAR_TYPE) \
    typedef union                         \
    {                                     \
        struct                            \
        {                                 \
            SCALAR_TYPE x;                \
            SCALAR_TYPE y;                \
        };                                \
        SCALAR_TYPE data[2];              \
    }

#define daxa_i32 int32_t
#define daxa_u32 uint32_t
#define daxa_f32 float
#define daxa_i64 int64_t
#define daxa_u64 uint64_t

_DAXA_DECL_VEC2_TYPE(float)
daxa_f32vec2;
_DAXA_DECL_VEC2_TYPE(double)
daxa_f64vec2;
_DAXA_DECL_VEC2_TYPE(uint32_t)
daxa_u32vec2;
_DAXA_DECL_VEC2_TYPE(int32_t)
daxa_i32vec2;

#define _DAXA_DECL_VEC3_TYPE(SCALAR_TYPE) \
    typedef union                         \
    {                                     \
        struct                            \
        {                                 \
            SCALAR_TYPE x;                \
            SCALAR_TYPE y;                \
            SCALAR_TYPE z;                \
        };                                \
        SCALAR_TYPE data[3];              \
    }

_DAXA_DECL_VEC3_TYPE(float)
daxa_f32vec3;
_DAXA_DECL_VEC3_TYPE(double)
daxa_f64vec3;
_DAXA_DECL_VEC3_TYPE(uint32_t)
daxa_u32vec3;
_DAXA_DECL_VEC3_TYPE(int32_t)
daxa_i32vec3;

#define _DAXA_DECL_VEC4_TYPE(SCALAR_TYPE) \
    typedef union                         \
    {                                     \
        struct                            \
        {                                 \
            SCALAR_TYPE x;                \
            SCALAR_TYPE y;                \
            SCALAR_TYPE z;                \
            SCALAR_TYPE w;                \
        };                                \
        SCALAR_TYPE data[4];              \
    }
_DAXA_DECL_VEC4_TYPE(float)
daxa_f32vec4;
_DAXA_DECL_VEC4_TYPE(double)
daxa_f64vec4;
_DAXA_DECL_VEC4_TYPE(uint32_t)
daxa_u32vec4;
_DAXA_DECL_VEC4_TYPE(int32_t)
daxa_i32vec4;
_DAXA_DECL_VEC2_TYPE(daxa_f32vec2)
daxa_f32mat2x2;
_DAXA_DECL_VEC3_TYPE(daxa_f32vec2)
daxa_f32mat2x3;
_DAXA_DECL_VEC4_TYPE(daxa_f32vec2)
daxa_f32mat2x4;
_DAXA_DECL_VEC2_TYPE(daxa_f64vec2)
daxa_f64mat2x2;
_DAXA_DECL_VEC3_TYPE(daxa_f64vec2)
daxa_f64mat2x3;
_DAXA_DECL_VEC4_TYPE(daxa_f64vec2)
daxa_f64mat2x4;
_DAXA_DECL_VEC2_TYPE(daxa_f32vec3)
daxa_f32mat3x2;
_DAXA_DECL_VEC3_TYPE(daxa_f32vec3)
daxa_f32mat3x3;
_DAXA_DECL_VEC4_TYPE(daxa_f32vec3)
daxa_f32mat3x4;
_DAXA_DECL_VEC2_TYPE(daxa_f64vec3)
daxa_f64mat3x2;
_DAXA_DECL_VEC3_TYPE(daxa_f64vec3)
daxa_f64mat3x3;
_DAXA_DECL_VEC4_TYPE(daxa_f64vec3)
daxa_f64mat3x4;
_DAXA_DECL_VEC2_TYPE(daxa_f32vec4)
daxa_f32mat4x2;
_DAXA_DECL_VEC3_TYPE(daxa_f32vec4)
daxa_f32mat4x3;
_DAXA_DECL_VEC4_TYPE(daxa_f32vec4)
daxa_f32mat4x4;
_DAXA_DECL_VEC2_TYPE(daxa_f64vec4)
daxa_f64mat4x2;
_DAXA_DECL_VEC3_TYPE(daxa_f64vec4)
daxa_f64mat4x3;
_DAXA_DECL_VEC4_TYPE(daxa_f64vec4)
daxa_f64mat4x4;
_DAXA_DECL_VEC2_TYPE(daxa_i32vec2)
daxa_i32mat2x2;
_DAXA_DECL_VEC3_TYPE(daxa_i32vec2)
daxa_i32mat2x3;
_DAXA_DECL_VEC4_TYPE(daxa_i32vec2)
daxa_i32mat2x4;
_DAXA_DECL_VEC2_TYPE(daxa_u32vec2)
daxa_u32mat2x2;
_DAXA_DECL_VEC3_TYPE(daxa_u32vec2)
daxa_u32mat2x3;
_DAXA_DECL_VEC4_TYPE(daxa_u32vec2)
daxa_u32mat2x4;
_DAXA_DECL_VEC2_TYPE(daxa_i32vec3)
daxa_i32mat3x2;
_DAXA_DECL_VEC3_TYPE(daxa_i32vec3)
daxa_i32mat3x3;
_DAXA_DECL_VEC4_TYPE(daxa_i32vec3)
daxa_i32mat3x4;
_DAXA_DECL_VEC2_TYPE(daxa_u32vec3)
daxa_u32mat3x2;
_DAXA_DECL_VEC3_TYPE(daxa_u32vec3)
daxa_u32mat3x3;
_DAXA_DECL_VEC4_TYPE(daxa_u32vec3)
daxa_u32mat3x4;
_DAXA_DECL_VEC2_TYPE(daxa_i32vec4)
daxa_i32mat4x2;
_DAXA_DECL_VEC3_TYPE(daxa_i32vec4)
daxa_i32mat4x3;
_DAXA_DECL_VEC4_TYPE(daxa_i32vec4)
daxa_i32mat4x4;
_DAXA_DECL_VEC2_TYPE(daxa_u32vec4)
daxa_u32mat4x2;
_DAXA_DECL_VEC3_TYPE(daxa_u32vec4)
daxa_u32mat4x3;
_DAXA_DECL_VEC4_TYPE(daxa_u32vec4)
daxa_u32mat4x4;

/// ABI STABLE OPTIONAL TYPE.
/// THIS TYPE MUST STAY IN SYNC WITH daxa::Optional
#define _DAXA_DECL_OPTIONAL(T) \
    typedef struct             \
    {                          \
        T value;               \
        daxa_Bool8 has_value;  \
    } daxa_Optional##T;

#define daxa_Optional(T) daxa_Optional##T

#define _DAXA_FIXED_LIST_SIZE_T uint32_t

/// ABI STABLE FIXED LIST TYPE.
/// THIS TYPE MUST STAY IN SYNC WITH daxa::FixedList
#define _DAXA_DECL_FIXED_LIST(T, CAPACITY) \
    typedef struct                         \
    {                                      \
        T data[CAPACITY];                  \
        _DAXA_FIXED_LIST_SIZE_T size;      \
    } daxa_FixedList##T##CAPACITY;

#define daxa_FixedList(T, CAPACITY) daxa_FixedList##T##CAPACITY

#define _DAXA_VARIANT_INDEX_TYPE daxa_i32

/// ABI STABLE VARIANT TYPE.
/// THIS TYPE MUST STAY IN SYNC WITH daxa::Variant
#define _DAXA_DECL_VARIANT(UNION)       \
    typedef struct                      \
    {                                   \
        _DAXA_VARIANT_INDEX_TYPE index; \
        UNION values;                   \
    } daxa_Variant##UNION;

#define daxa_Variant(UNION) daxa_Variant##UNION

typedef struct
{
    uint32_t base_mip_level;
    uint32_t level_count;
    uint32_t base_array_layer;
    uint32_t layer_count;
} daxa_ImageMipArraySlice;

typedef struct
{
    uint32_t mip_level;
    uint32_t base_array_layer;
    uint32_t layer_count;
} daxa_ImageArraySlice;

typedef struct
{
    uint32_t mip_level;
    uint32_t array_layer;
} daxa_ImageSlice;

typedef uint32_t daxa_MemoryFlags;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_NONE = 0x00000000;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_DEDICATED_MEMORY = 0x00000001;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_CAN_ALIAS = 0x00000200;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_HOST_ACCESS_SEQUENTIAL_WRITE = 0x00000400;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_HOST_ACCESS_RANDOM = 0x00000800;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_STRATEGY_MIN_MEMORY = 0x00010000;
static const daxa_MemoryFlags DAXA_MEMORY_FLAG_STRATEGY_MIN_TIME = 0x00020000;

typedef struct
{
    VkMemoryRequirements requirements;
    daxa_MemoryFlags flags;
} daxa_MemoryBlockInfo;

DAXA_EXPORT daxa_MemoryBlockInfo const *
daxa_memory_info(daxa_MemoryBlock memory_block);

DAXA_EXPORT uint64_t
daxa_memory_inc_refcnt(daxa_MemoryBlock memory_block);
DAXA_EXPORT uint64_t
daxa_memory_dec_refcnt(daxa_MemoryBlock memory_block);

typedef struct
{
    daxa_MemoryBlock memory_block;
    size_t offset;
} daxa_ManualAllocInfo;

typedef union
{
    daxa_MemoryFlags auto_alloc_info;
    daxa_ManualAllocInfo manual_alloc_info;
} daxa_AllocInfoUnion;
_DAXA_DECL_VARIANT(daxa_AllocInfoUnion)

typedef struct
{
    uint32_t query_count;
    daxa_StringView name;
} daxa_TimelineQueryPoolInfo;

DAXA_EXPORT daxa_TimelineQueryPoolInfo const *
daxa_timeline_query_pool_info(daxa_TimelineQueryPool timeline_query_pool);

DAXA_EXPORT void
daxa_timeline_query_pool_query_results(daxa_TimelineQueryPool timeline_query_pool, uint64_t * out_counnt, uint64_t * out_results);

DAXA_EXPORT uint64_t
daxa_timeline_query_pool_inc_refcnt(daxa_TimelineQueryPool timeline_query_pool);
DAXA_EXPORT uint64_t
daxa_timeline_query_pool_dec_refcnt(daxa_TimelineQueryPool timeline_query_pool);

#endif // #ifndef __DAXA_TYPES_H__
