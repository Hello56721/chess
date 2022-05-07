#include <glad/glad.h>
#include <iostream>

#include "window.hpp"
#include "utilities.hpp"

#include "application.hpp"

using chess::application_t;

application_t::context_debugger::context_debugger()
{
    #ifndef NDEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    
    glDebugMessageCallback([] (GLenum,GLenum,GLuint,GLenum,GLsizei,const GLchar *p_message,const void*) {
        std::clog << "[OPENGL]: " << p_message;
        std::clog << std::endl;
    }, nullptr);
    
    std::cout << "[INFO]: Enabled OpenGL context debugging.\n";
    #endif
}

application_t::application_t(): m_window(window_t::get_instance()), m_renderer(2)
{
    m_window.show();
}

void application_t::update(double p_delta_time)
{
    UNUSED_PARAM(p_delta_time);
}

void application_t::render()
{
    m_board.render();
    
    m_renderer.begin();
    
    renderer_t::quad_t orange_quad = {};
    orange_quad.position.x = -0.5f;
    orange_quad.position.y = 0.5f;
    orange_quad.size.x = 1.0f;
    orange_quad.size.y = 1.0f;
    orange_quad.color = { 1.0f, 1.0f, 0.5f, 1.0f };
    m_renderer.draw_quad(orange_quad);
    
    m_renderer.end();
    
    m_window.update();
}

bool application_t::is_open() const
{
    return m_window.is_open();
}

application_t::~application_t()
{
    
}