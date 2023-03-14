#pragma once

#include <daxa/daxa.inl>

struct MipmappingGpuInput
{
    daxa_f32vec3 paint_col;
    daxa_f32 mouse_x;
    daxa_f32 mouse_y;
    daxa_f32 p_mouse_x;
    daxa_f32 p_mouse_y;
    daxa_f32 paint_radius;
};
DAXA_ENABLE_BUFFER_PTR(MipmappingGpuInput)

struct MipmappingComputePushConstant
{
    daxa_RWImage(2D,f32) image;
    daxa_RWBufferPtr(MipmappingGpuInput) gpu_input;
    daxa_u32vec2 frame_dim;
};

struct ConditionalUploadStruct
{
    daxa_u32 value;
};

struct DrawVertex
{
    daxa_f32vec4 pos, col;
};
DAXA_ENABLE_BUFFER_PTR(DrawVertex)
struct DrawPush
{
    daxa_BufferPtr(DrawVertex) vertex_buffer;
};
