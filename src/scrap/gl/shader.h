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

#ifndef SRC_SCRAP_GL_SHADER_H_
#define SRC_SCRAP_GL_SHADER_H_

#include <string>
#include "scrap/gl/gl_config.h"

namespace scrap {
namespace gl {

enum ShaderType {
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_VERTEX_SHADER
};

// A wrapper around GLSL shaders using RAII.
class Shader {
 public:
  // Creates a new shader of the given type with the provided source.
  // TODO(andrew): error checking.
  Shader(ShaderType type, std::string source);
  ~Shader();
  int shader() { return shader_; }
 private:
  ShaderType type_;
  int shader_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_SHADER_H_
