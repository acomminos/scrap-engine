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
//
#ifndef SRC_SCRAP_GL_PROGRAM_H_
#define SRC_SCRAP_GL_PROGRAM_H_

#include <string>
#include "scrap/gl/shader.h"

namespace scrap {
namespace gl {

// A wrapper around a GLSL shader program.
// Shaders attached to this program are provided the following:
// Attributes:
// - pos : mat3 (position)
// Uniforms:
// - tex : sampler2d (texture)
// - mvp : mat4 (MVP matrix)
class Program {
 public:
  // Registers a new shader program with OpenGL.
  Program(Shader *vertex_shader, Shader *fragment_shader);
  ~Program();
 private:
  Shader *vertex_shader_;
  Shader *fragment_shader_;
  int program_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_PROGRAM_H_
