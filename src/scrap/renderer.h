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

#ifndef SRC_SCRAP_RENDERER_H_
#define SRC_SCRAP_RENDERER_H_

#include <map>
#include <set>
#include <memory>
#include "scrap/doodad.h"
#include "scrap/camera.h"

namespace scrap {

// The base implementation of Renderer draws Doodads with shader programs
// provided the following attributes:
// - in vec3 a_pos (3d position)
// - in vec3 a_uv (2d uv coordinates)
// - uniform mat4 u_mvp (model/view/projection matrix)
// - uniform sampler2d u_tex (uv texture)
// As well as each doodad's material's custom uniforms.
class Renderer {
 public:
  Renderer();
  ~Renderer();
  void SetProgram(gl::Program *program);
  void Render(Camera &camera, Doodad &doodad) const;
 private:
  gl::Program *program_;
  GLuint a_pos_;
  GLuint a_uv_;
  GLuint u_mvp_;
  GLuint u_tex_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_RENDERER_H_
