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

#include "scrap/gl/model_renderer.h"
#include <glm/gtc/type_ptr.hpp>
#include "scrap/scene/model_scene.h"

scrap::gl::ModelRenderer::ModelRenderer() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

scrap::gl::ModelRenderer::~ModelRenderer() {
}

void scrap::gl::ModelRenderer::SetProgram(const std::shared_ptr<Program> &program) {
    program_ = program;
    a_pos_ = program->GetAttribLocation("a_pos");
    a_normal_ = program->GetAttribLocation("a_normal");
    a_uv_ = program->GetAttribLocation("a_uv");
    u_tex_ = program->GetUniformLocation("u_tex");
    u_mvp_ = program->GetUniformLocation("u_mvp");
}

void scrap::gl::ModelRenderer::Render(const ModelScene &scene) const {
    assert(program_);
    assert(program_->is_linked());
    program_->Use();

    const Camera &camera = scene.active_camera();
    const std::vector<Doodad> &doodads = scene.doodads();

    glEnableVertexAttribArray(a_pos_);
    glEnableVertexAttribArray(a_normal_);
    glEnableVertexAttribArray(a_uv_);

    for (auto it = doodads.cbegin(); it != doodads.cend(); it++) {
        const Doodad &doodad = *it;
        gl::Model &model = doodad.model();
        gl::Material &material = doodad.material();

        // TODO(andrew): support for material shaders

        glm::mat4 transform = camera.GetTransform() * doodad.matrix();
        glUniformMatrix4fv(u_mvp_, 1, GL_FALSE, glm::value_ptr(transform));

        glActiveTexture(GL_TEXTURE0);
        // TODO(andrew): render texture with material's shader
        glBindTexture(GL_TEXTURE_2D, material.texture().texture());
        glUniform1i(u_tex_, 0);

        const AttribBuffer *position_buffer = model.position_buffer();
        const AttribBuffer *normal_buffer = model.normal_buffer();
        const AttribBuffer *uv_buffer = model.uv_buffer();

        program_->BindVertexAttribBuffer(a_pos_, *position_buffer);
        program_->BindVertexAttribBuffer(a_normal_, *normal_buffer);
        program_->BindVertexAttribBuffer(a_uv_, *uv_buffer);

        glDrawArrays(GL_TRIANGLES, 0, model.num_vertices());
    }

    glDisableVertexAttribArray(a_pos_);
    glDisableVertexAttribArray(a_normal_);
    glDisableVertexAttribArray(a_uv_);
}

//  void scrap::gl::ModelRenderer::DrawGUI(ModelScene &scene) {
//      // TODO(andrew): use custom GUI GL program?
//      glBindBuffer(GL_ARRAY_BUFFER, gui_buffer_);
//      glVertexAttribPointer(a_pos_, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4,
//                            NULL);
//      glVertexAttribPointer(a_uv_, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4,
//                            (GLvoid*)(sizeof(GLfloat) * 2));
//      cairo_set_source_rgba(cairo_ctx_, 0.0f, 0.0f, 0.0f, 0.0f);
//      cairo_rectangle(cairo_ctx_, 0, 0, width_, height_);
//      cairo_fill(cairo_ctx_);
//      cairo_save(cairo_ctx_);
//      scene.DrawGUI(cairo_ctx_);
//      cairo_restore(cairo_ctx_);
//      cairo_surface_flush(cairo_surface_);
//      glActiveTexture(GL_TEXTURE0);
//      unsigned char *data = cairo_image_surface_get_data(cairo_surface_);
//      gui_texture_.SetData(GL_UNSIGNED_BYTE, data, width_, height_);
//      glBindTexture(GL_TEXTURE_2D, gui_texture_.texture());
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//      glUniform1i(u_tex_, 0);
//      
//      glUniformMatrix4fv(u_mvp_, 1, GL_FALSE, glm::value_ptr(glm::mat4()));
//      glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//  }
