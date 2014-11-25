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

scrap::gl::Program::Program(scrap::gl::Shader *vertex_shader,
    scrap::gl::Shader *fragment_shader) :
    vertex_shader_(vertex_shader),
    fragment_shader_(fragment_shader) {
    program_ = glCreateProgram();
    glAttachShader(program_, vertex_shader->shader());
    glAttachShader(program_, fragment_shader->shader());
    glLinkProgram(program_);
}

scrap::gl::Program::~Program() {
    glDeleteProgram(program_);
}
