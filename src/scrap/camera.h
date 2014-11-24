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

#ifndef SCRAP_CAMERA_H_
#define SCRAP_CAMERA_H_

#include <glm/glm.hpp>

namespace scrap {

// The camera provides an interface to producing a 'view' matrix in the
// MVP (model-view-projection) transformation strategy.
class Camera {
 public:
  Camera(glm::vec3 pos, glm::vec3 rot);
  // Rotates the camera about its current position by the given amount of
  // radians.
  void Rotate(float x, float y, float z);
  void Translate(float x, float y, float z);
  glm::mat4 matrix() { return matrix_; };
 private:
  glm::mat4 matrix_;
};

}  // namespace scrap

#endif  // SCRAP_CAMERA_H_
