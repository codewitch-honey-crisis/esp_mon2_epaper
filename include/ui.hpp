#pragma once
#include <uix.hpp>
#include <circular_buffer.hpp>
// declare the types for our controls and other things
using screen_t = uix::screen<960,540,gfx::gsc_pixel<4>>;

using label_t = uix::label<typename screen_t::control_surface_type>;
using svg_box_t = uix::svg_box<typename screen_t::control_surface_type>;
using canvas_t = uix::canvas<typename screen_t::control_surface_type>;
// X11 colors (used for screen)
using color_t = gfx::color<typename screen_t::pixel_type>;
// RGBA8888 X11 colors (used for controls)
using color32_t = gfx::color<gfx::rgba_pixel<32>>;
// circular buffer for graphs
using buffer_t = circular_buffer<float,100>;

// the buffers hold the graph data for the CPU
extern buffer_t cpu_buffers[];
// the array holds the bar/label data for the CPU
extern float cpu_values[];
// the max temperature received for the CPU
extern int cpu_max_temp;
// the colors for the CPU bar and graph
extern gfx::rgba_pixel<32> cpu_colors[];
// the buffers hold the graph data for the GPU
extern buffer_t gpu_buffers[];
// the array holds the bar/label data for the GPU
extern float gpu_values[];
// the max temperature received for the GPU
extern int gpu_max_temp;
// the colors for the GPU bar and graph
extern gfx::rgba_pixel<32> gpu_colors[];

constexpr static const int lcd_buffer_size = 64 * 1024;

// the screen that holds the controls
extern screen_t main_screen;

// the controls for the CPU
extern label_t cpu_label;
extern label_t cpu_temp_label;
extern canvas_t cpu_bar;
extern canvas_t cpu_graph;

// the controls for the GPU
extern label_t gpu_label;
extern label_t gpu_temp_label;
extern canvas_t gpu_bar;
extern canvas_t gpu_graph;

// the controls for the disconnected "screen"
extern label_t disconnected_label;
extern svg_box_t disconnected_svg;

extern void main_screen_init(screen_t::on_flush_callback_type flush_callback, 
                            void* flush_callback_state = nullptr);