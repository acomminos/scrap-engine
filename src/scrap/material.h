#ifndef SRC_SCRAP_MATERIAL_H_
#define SRC_SCRAP_MATERIAL_H_

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
  void SetCustomUniform(std::string name, int value);
  void SetCustomUniform(std::string name, float value);

  std::map<std::string, int> custom_int_uniforms_;
  std::map<std::string, float> custom_float_uniforms_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_MATERIAL_H_
