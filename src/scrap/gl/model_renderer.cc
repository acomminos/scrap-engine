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

scrap::gl::ModelRenderer::ModelRenderer(const ModelScene &scene,
                                        const Program &program) :
                          scene_(scene), program_(program) {
    assert(program.is_linked());

    a_pos_ = program.GetAttribLocation("a_pos");
    a_uv_ = program.GetAttribLocation("a_uv");
    u_tex_ = program.GetUniformLocation("u_tex");
    u_mvp_ = program.GetUniformLocation("u_mvp");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

scrap::gl::ModelRenderer::~ModelRenderer() {
}

void scrap::gl::ModelRenderer::Render() const {
    program_.Use();
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Camera *camera = scene_.active_camera();
    const std::vector<Doodad*> &doodads = scene_.doodads();

    glEnableVertexAttribArray(a_pos_);
    glEnableVertexAttribArray(a_normal_);
    glEnableVertexAttribArray(a_uv_);

    for (auto it = doodads.cbegin(); it != doodads.cend(); it++) {
        Doodad *doodad = *it;
        gl::Model &model = doodad->model();
        gl::Material &material = doodad->material();

        // TODO(andrew): support for material shaders

        glUniform1i(u_tex_, material.texture().texture());
        glm::mat4 transform = camera->GetTransform() * doodad->matrix();
        glUniformMatrix4fv(u_mvp_, 1, GL_FALSE, glm::value_ptr(transform));

        AttribBuffer position_buffer = model.position_buffer();
        AttribBuffer position_buffer = model.position_buffer();
        AttribBuffer position_buffer = model.position_buffer();
        position_buffer.SetVertexAttribPointer(a_pos_);

        DrawElements(model.array_buffer(), model.num_elements());
    }

    glDisableVertexAttribArray(a_pos_);
    glDisableVertexAttribArray(a_normal_);
    glDisableVertexAttribArray(a_uv_);
}

void scrap::gl::ModelRenderer::DrawElements(GLuint buffer, GLsizei num_elements) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(a_pos_, 3, GL_FLOAT, GL_FALSE, sizeof(gl::Element),
                          NULL);
    glVertexAttribPointer(a_uv_, 2, GL_FLOAT, GL_FALSE, sizeof(gl::Element),
                          (GLvoid*)(sizeof(GLfloat) * 3));
    glDrawArrays(GL_TRIANGLES, 0, num_elements);
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
