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

// A material contains a texture with a particular shader.
class Material {
 public:
  Material(Texture &texture, gl::Program &program) : texture_(texture),
                                                     program_(program) {};
  ~Material();
  Texture &texture() const { return texture_; }
  gl::Program &program() const { return program_; }
  std::map<std::string, int> get_custom_int_uniforms() {
    return custom_int_uniforms_;
  }
  std::map<std::string, float> get_custom_float_uniforms() {
    return custom_float_uniforms_;
  }
 private:
  Texture &texture_;
  gl::Program &program_;

  // Sets a custom shader uniform to use in a custom shader.
  void SetCustomUniform(std::string name, int value) {
    custom_int_uniforms_[name] = value;
  }
  void SetCustomUniform(std::string name, float value) {
    custom_float_uniforms_[name] = value;
  }

  std::map<std::string, int> custom_int_uniforms_;
  std::map<std::string, float> custom_float_uniforms_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_MATERIAL_H_
