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

#ifndef SRC_SCRAP_CAMERA_H_
#define SRC_SCRAP_CAMERA_H_

#include <glm/glm.hpp>

namespace scrap {

// The camera provides an interface to producing a view and projection matrix
// in the MVP (model-view-projection) transformation strategy.
class Camera {
 public:
  Camera(float fov, float ratio, float near, float far);
  // Rotates the camera about its current position by the given amount of
  // radians.
  void Rotate(float x, float y, float z);
  void Translate(float x, float y, float z);
  void set_fov(float fov) { fov_ = fov; }
  void set_ratio(float ratio) { ratio_ = ratio; }
  void set_near(float near) { near_ = near; }
  void set_far(float far) { far_ = far; }
  glm::mat4 GetTransform() const;
  glm::mat4 ToModelCoords(const glm::mat4 &mat);
 private:
  float fov_;
  float ratio_;
  float near_;
  float far_;
  glm::mat4 rotation_;
  glm::vec3 position_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_CAMERA_H_
