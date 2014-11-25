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

#ifndef SRC_SCRAP_DOODAD_H_
#define SRC_SCRAP_DOODAD_H_

#include <glm/glm.hpp>
#include "scrap/model.h"
#include "scrap/gl/program.h"

namespace scrap {

// A doodad is an object in the game world. It is given a (preferably shared)
// model instance to transform and represent in user coordinates.
class Doodad {
 public:
  // Creates a new Doodad with the given model, position, rotation, and scale.
  Doodad(Model *model, glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
  // Creates a new Doodad with the given model located at the origin.
  Doodad(Model *model) : model_(model) {}
  // Rotates the doodad about its current position using the specified values
  // (in radians).
  void Rotate(float x, float y, float z);
  // Translates the doodad in world coordinates by the given values.
  void Translate(float x, float y, float z);
  // Scales the doodad by the given scale factors. Applied relatively.
  void Scale(float x, float y, float z);
  Model* model() { return model_; }
  // Returns the transformation matrix applied to the Doodad's model.
  glm::mat4 matrix() { return matrix_; }
 private:
  Model *model_;
  gl::Program *program_;
  glm::mat4 matrix_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_DOODAD_H_
