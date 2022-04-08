#include <stdexcept>
#include <iostream>

#include <glad/glad.h>

#include "window.hpp"

static const uint16_t WIDTH = 800;
static const uint16_t HEIGHT = 600;

static void glfw_error_callback(int p_code, const char* p_message)
{
    std::cerr << "[GLFW ERROR " << p_code << "]: " << p_message << "\n";
}

window_t& window_t::get_instance()
{
    static window_t instance;
    return instance;
}

void window_t::show() const
{
    glfwShowWindow(m_handle);
}

bool window_t::is_open() const
{
    return !glfwWindowShouldClose(m_handle);
}

void window_t::update() const 
{
    glfwSwapBuffers(m_handle);
    glfwPollEvents();
}

window_t::~window_t()
{
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}

window_t::window_t()
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize glfw.");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_handle = glfwCreateWindow(WIDTH, HEIGHT, "Chess", nullptr, nullptr);
    
    if (!m_handle)
    {
        throw std::runtime_error("failed to create the glfw window.");
    }
    
    const GLFWvidmode* video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(m_handle, (video_mode->width - WIDTH) / 2, (video_mode->height - HEIGHT) / 2);
    
    glfwMakeContextCurrent(m_handle);
    
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        throw std::runtime_error("failed to initialize glad.");
    }
}