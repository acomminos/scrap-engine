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
    VertexShader = GL_VERTEX_SHADER,
    FragmentShader = GL_FRAGMENT_SHADER
};

// A wrapper around GLSL shaders using RAII.
class Shader {
 public:
  // Creates a new shader of the given type.
  Shader(ShaderType type);
  ~Shader();
  // Compiles the provided shader source into this shader.
  // Returns true if the shader compiled succesfully.
  bool Compile(std::string source);
  bool CompileFromFile(std::string shader_name);
  bool is_compiled() const { return compiled_; }
  GLuint shader() const { return shader_; }
 private:
  ShaderType type_;
  GLuint shader_;
  bool compiled_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_SHADER_H_
