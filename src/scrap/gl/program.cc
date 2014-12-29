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

    GLint result;
    glGetProgramiv(program_, GL_LINK_STATUS, &result);
    linked_ = result;
    return result;
}

void scrap::gl::Program::Use() {
    glUseProgram(program_);
}

/*
void scrap::gl::Program::DrawElements(GLuint buffer, GLsizei num_elements) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(a_pos_, sizeof(GLfloat) * 3, GL_FLOAT, GL_FALSE,
                          sizeof(GLfloat) * 2, NULL);
    glDrawArrays(GL_TRIANGLES, 0, num_elements);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
*/

GLuint scrap::gl::Program::GetUniformLocation(const char *name) const {
    return glGetUniformLocation(program_, name);
}

GLuint scrap::gl::Program::GetAttribLocation(const char *name) const {
    return glGetAttribLocation(program_, name);
}

/*
void scrap::gl::Program::SetVertexAttribPointer(GLuint index, GLsizei size,
    GLenum type, GLboolean normalized, GLuint stride, const GLvoid *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
*/
