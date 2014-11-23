#include "gl/shader_program.h"

scrap::gl::Program::Program(scrap::gl::VertexShader vertex_shader,
    scrap::gl::FragmentShader fragment_shader) :
    vertex_shader_(vertex_shader),
    fragment_shader_(fragment_shader) {
    _program = glCreateProgram();
    glAttachShader(program_, vertex_shader.shader);
    glAttachShader(program_, fragment_shader.shader);
    glLinkProgram(program_);
}

scrap::gl::Program::~Program() {
    glDeleteProgram(program);
}
