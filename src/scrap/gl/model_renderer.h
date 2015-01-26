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

#ifndef SRC_SCRAP_GL_MODEL_RENDERER_H_
#define SRC_SCRAP_GL_MODEL_RENDERER_H_

#include <map>
#include <set>
#include <memory>
#include "scrap/doodad.h"
#include "scrap/camera.h"
#include "scrap/gl/texture.h"

namespace scrap {

class ModelScene;

namespace gl {

// The base implementation of ModelRenderer renders a ModelScene with a shader
// provided the following attributes:
// - attribute vec3 a_pos (3d position)
// - attribute vec3 a_normal (3d normal)
// - attribute vec2 a_uv (2d uv coordinates)
// - uniform mat4 u_mvp (model/view/projection matrix)
// - uniform sampler2d u_tex (uv texture)
// Custom uniforms can be specified by materials.
class ModelRenderer {
 public:
  ModelRenderer(const ModelScene &scene, const Program &program);
  ~ModelRenderer();
  // Draws all Doodads in the scene.
  void Render() const;
 private:
  const ModelScene &scene_;
  const gl::Program &program_;
  GLuint a_pos_;
  GLuint a_normal_;
  GLuint a_uv_;
  GLuint u_mvp_;
  GLuint u_tex_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_MODEL_RENDERER_H_
