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
  void Rotate(double x, double y, double z);
  void Translate(double x, double y, double z);
  glm::mat4 matrix() { return matrix_; };
 private:
  glm::mat4 matrix_;
};

}  // namespace scrap

#endif  // SCRAP_CAMERA_H_
