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

#include "scrap/doodad.h"
#include <glm/gtc/matrix_transform.hpp>

scrap::Doodad::Doodad(gl::Model &model, gl::Material &material) : model_(model),
                                                           material_(material),
                                                           matrix_(1.0f) {
    // TODO(andrew)
}

void scrap::Doodad::Rotate(float x, float y, float z) {
    // TODO(andrew)
}

void scrap::Doodad::Translate(float x, float y, float z) {
    Transform(glm::translate(matrix_, glm::vec3(x, y, z)));
}

void scrap::Doodad::Scale(float x, float y, float z) {
    Transform(glm::scale(matrix_, glm::vec3(x, y, z)));
}

void scrap::Doodad::Transform(const glm::mat4 &matrix) {
    matrix_ = matrix * matrix_;
}
