#version 330 core
layout (location = 0) in vec2 a_position;
layout (location = 1) in vec3 a_color;

out vec3 vertex_color;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    gl_Position = projection * model * vec4(a_position, 0.0, 1.0);
    vertex_color = a_color;
}