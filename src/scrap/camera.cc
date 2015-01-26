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

#include "scrap/camera.h"
#include <glm/gtc/matrix_transform.hpp>

scrap::Camera::Camera(float fov, float ratio, float near, float far) :
    fov_(fov), ratio_(ratio), near_(near), far_(far) {
}

void scrap::Camera::Rotate(float x, float y, float z) {
    // TODO(andrew): split into Rotate{X,Y,Z}?
    if (x != 0)
        rotation_ = glm::rotate(rotation_, x, glm::vec3(1, 0, 0));
    if (y != 0)
        rotation_ = glm::rotate(rotation_, y, glm::vec3(0, 1, 0));
    if (y != 0)
        rotation_ = glm::rotate(rotation_, z, glm::vec3(0, 0, 1));
}

glm::mat4 scrap::Camera::GetTransform() const {
    glm::mat4 transform;
    transform *= glm::perspective(fov_, ratio_, near_, far_);
    glm::translate(transform, position_);
    transform *= -rotation_;
    return transform;
}
