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

#include "scrap/scene/model_scene.h"
#include <iterator>
#include <cassert>
#include "scrap/gl/gl_config.h"

scrap::ModelScene::ModelScene() {
    glEnable(GL_DEPTH_TEST);
    
    // TODO(andrew): populate programs_
}

void scrap::ModelScene::Update(double delta_time) {
}

void scrap::ModelScene::Render() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 mat_vproj = active_camera_->GetTransform();
    for (auto it_map = doodads_.cbegin(); it_map != doodads_.cend(); it_map++) {
        gl::Program *program = it_map->first;
        std::vector<Doodad*> *list = it_map->second;

        program->Begin();
        for (auto it_vec = list->cbegin(); it_vec != list->cend(); it_vec++) {
            Doodad *doodad = *it_vec;
            Model &model = doodad->model();
            Material &material = doodad->material();
            glm::mat4 mat_model = doodad->matrix();
            program->SetPositionPointer(model.array_buffer(), 0, 0);
            program->SetUVMapPointer(model.uv_buffer(), 0, 0);
            program->SetMVPMatrix(mat_model * mat_vproj);
            program->SetTexture(material.texture().texture());

            glBindBuffer(GL_ARRAY_BUFFER, model.array_buffer());
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.element_buffer());
            // TODO(andrew): setup vertex shader
            glDrawElements(GL_TRIANGLES, model.num_vertices(), GL_UNSIGNED_INT,
                           NULL);
        }
        program->End();
    }
}

void scrap::ModelScene::OnSizeChange(int width, int height) {
    glViewport(0, 0, width, height);
    active_camera_->set_ratio((float)width/(float)height);
}

void scrap::ModelScene::AddDoodad(Doodad &doodad) {
    gl::Program &program = doodad.material().program();
    std::vector<Doodad*> *doodad_list = doodads_[&program];
    doodad_list->push_back(&doodad);
}
