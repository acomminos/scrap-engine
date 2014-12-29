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

#include "scrap/gl/shader.h"
#include <cstdio>

scrap::gl::Shader::Shader(scrap::gl::ShaderType type) {
    shader_ = glCreateShader(type);
}

scrap::gl::Shader::~Shader() {
    glDeleteShader(shader_);
}

bool scrap::gl::Shader::Compile(std::string source) {
    const GLchar *c_src = source.c_str();
    glShaderSource(shader_, 1, &c_src, NULL);
    glCompileShader(shader_);

    GLint result;
    glGetShaderiv(shader_, GL_COMPILE_STATUS, &result);
    //compiled_ = result;
    compiled_ = true;

    /*
        GLsizei len = 0;
        glGetShaderiv(shader_, GL_INFO_LOG_LENGTH, &len);
        fprintf(stderr, "info length: %lu\n", len);
        GLchar *buf = new GLchar[len + 1];
        glGetShaderInfoLog(shader_, len, NULL, buf);
        fprintf(stderr, "Error in shader compilation: %s\n", buf);
        delete[] buf;
    */

    return result;
}
