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

#include "scrap/renderer.h"

scrap::Renderer::Renderer() {

}

scrap::Renderer::~Renderer() {

}

void scrap::Renderer::SetProgram(gl::Program *program) {
    program_ = program;
    program->Use();
    a_pos_ = program->GetAttribLocation("a_pos");
    a_uv_ = program->GetAttribLocation("a_uv");
    u_mvp_ = program->GetUniformLocation("u_mvp");
    u_tex_ = program->GetUniformLocation("u_tex");
}

void scrap::Renderer::Render(Camera &camera, Doodad &doodad) const {
    assert(program_);

    gl::Model &model = doodad.model();
    gl::Material &material = doodad.material();

    auto int_uniforms = material.get_custom_int_uniforms();
    auto float_uniforms = material.get_custom_float_uniforms();
    
    for (auto it = int_uniforms.cbegin(); it != int_uniforms.cend(); it++) {
        GLuint uniform = program_->GetUniformLocation(it->first.c_str());
        program_->SetUniform(uniform, it->second);
    }

    for (auto it = float_uniforms.cbegin(); it != float_uniforms.cend(); it++) {
        GLuint uniform = program_->GetUniformLocation(it->first.c_str());
        program_->SetUniform(uniform, it->second);
    }
}
