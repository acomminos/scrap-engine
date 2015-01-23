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

#ifndef SRC_SCRAP_MATERIAL_H_
#define SRC_SCRAP_MATERIAL_H_

#include <string>
#include <map>
#include "scrap/gl/gl_config.h"
#include "scrap/gl/program.h"
#include "scrap/gl/texture.h"

namespace scrap {
namespace gl {

// TODO(andrew): move elsewhere
typedef struct {
    GLuint buffer;
    GLint size;
    GLenum type;
    GLboolean normalized;
    GLsizei stride;
} VertexAttrib;

// A material contains a texture with a particular shader.
class Material {
 public:
  Material(std::shared_ptr<Texture> &texture, gl::Program *program) :
        texture_(texture), program_(program) {};
  Material(std::shared_ptr<Texture> &texture) : texture_(texture),
                                                program_(nullptr) {}
  ~Material();
  const Texture &texture() const { return *texture_; }
  // Returns the custom gl::Program used by this material, or nullptr if it
  // uses the default program.
  gl::Program *program() const { return program_; }
  std::map<std::string, int> get_custom_int_uniforms() {
    return custom_int_uniforms_;
  }
  std::map<std::string, float> get_custom_float_uniforms() {
    return custom_float_uniforms_;
  }
  std::map<std::string, VertexAttrib> get_custom_attribs() {
    return custom_attribs_;
  }
 private:
  std::shared_ptr<Texture> texture_;
  bool has_program_;
  gl::Program *program_;

  // Sets a custom shader uniform to use in a custom shader.
  void SetCustomUniform(std::string name, int value) {
    custom_int_uniforms_[name] = value;
  }
  void SetCustomUniform(std::string name, float value) {
    custom_float_uniforms_[name] = value;
  }
  void SetCustomVertexAttrib(std::string name, GLvoid *data, GLint size,
                             GLenum type, GLboolean normalized,
                             GLsizei stride) {
    GLuint buffer;
    //glGenBuffers(1, &buffer);
    VertexAttrib attrib = { buffer, size, type, normalized, stride };
    custom_attribs_[name] = attrib;
  }

  bool UnsetCustomVertexAttrib(std::string name) {
    VertexAttrib &attrib = custom_attribs_[name];
    GLuint buffer = attrib.buffer;
    //glDeleteBuffers(1, &buffer);
  }

  std::map<std::string, int> custom_int_uniforms_;
  std::map<std::string, float> custom_float_uniforms_;
  std::map<std::string, VertexAttrib> custom_attribs_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_MATERIAL_H_
