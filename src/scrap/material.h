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
#include "gl/gl_config.h"

namespace scrap {

// A material contains a texture and UV coordinates for a particular mesh.
// Materials can also specify custom shader programs to use.
class Material {
 public:
  static Material RGBA(const char *texture, int width, const int *uv,
                       int num_coords);
  ~Material();
  uint32_t format() { return format_; }
  uint32_t texture() { return texture_; }
  uint32_t uv_buffer() { return uv_buffer_; }
  uint32_t num_coords() { return num_coords_; }
  std::string program_name() { return program_name_; }
 private:
  Material(int format, const char *texture, int width, const int *uv, int num_coords);
  uint32_t format_;
  // A TEXTURE_2D buffer.
  uint32_t texture_;
  // An array buffer storing (u,v) tuples.
  uint32_t uv_buffer_;
  uint32_t num_coords_;
  std::string program_name_;

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

}  // namespace scrap

#endif  // SRC_SCRAP_MATERIAL_H_
