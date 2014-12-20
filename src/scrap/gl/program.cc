// Copyright © 2014 Andrew Comminos <andrew@morlunk.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "scrap/gl/program.h"

scrap::gl::Program::Program() {
    program_ = glCreateProgram();
}

scrap::gl::Program::~Program() {
    glDeleteProgram(program_);
}

bool scrap::gl::Program::Link(std::unique_ptr<scrap::gl::Shader> vertex_shader,
    std::unique_ptr<scrap::gl::Shader> fragment_shader) {
    assert(vertex_shader->is_compiled() && fragment_shader->is_compiled());
    vertex_shader_ = std::move(vertex_shader);
    fragment_shader_ = std::move(fragment_shader);

    glAttachShader(program_, vertex_shader->shader());
    glAttachShader(program_, fragment_shader->shader());
    glLinkProgram(program_);

    // Retrieve basic shader properties
    u_mvp_ = glGetUniformLocation(program_, "u_mvp");
    u_tex_ = glGetUniformLocation(program_, "u_tex");
    a_pos_ = glGetAttribLocation(program_, "a_pos");
    a_uv_ = glGetAttribLocation(program_, "a_uv");

    GLint result;
    glGetProgramiv(program_, GL_LINK_STATUS, &result);
    linked_ = result;
    return result;
}

void scrap::gl::Program::Begin() {
    glUseProgram(program_);
    glEnableVertexAttribArray(a_pos_);
    glEnableVertexAttribArray(a_uv_);
}

void scrap::gl::Program::End() {
    glDisableVertexAttribArray(a_pos_);
    glDisableVertexAttribArray(a_uv_);
    glUseProgram(0);
}

void scrap::gl::Program::SetPositionPointer(GLuint buffer, GLuint offset,
                                            GLuint stride) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(a_pos_, sizeof(GLfloat) * 3, GL_FLOAT, false, stride,
                          NULL);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void scrap::gl::Program::SetUVMapPointer(GLuint buffer, GLuint offset,
                                         GLuint stride) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(a_uv_, sizeof(GLfloat) * 2, GL_FLOAT, false, stride,
                          NULL);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void scrap::gl::Program::SetMVPMatrix(const glm::mat4 &mvp) {
    //glUniformMatrix(u_mvp_, mvp.
}

void scrap::gl::Program::SetTexture(GLuint texture) {
    glUniform1i(u_tex_, texture);
}
