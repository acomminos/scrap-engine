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
#include <memory>
#include <glm/glm.hpp>
#include "scrap/gl/shader.h"
#include "scrap/model.h"

namespace scrap {
namespace gl {

// A wrapper around a GLSL shader program.
// Uses std::unique_ptr to manage lifecycle of OpenGL state.
// All shaders are provided the following parameters:
// - attrib vec3 pos
// - attrib vec2 uv
// - uniform mat4 mvp
// - uniform sampler2d tex
// Custom shaders can use uniforms provided by Doodads as input.
class Program {
 public:
  // Registers a new shader program with OpenGL.
  Program();
  ~Program();

  // Attaches the given shaders, and links this program.
  // Returns an OpenGL error code.
  int Link(std::unique_ptr<scrap::gl::Shader> vertex_shader,
           std::unique_ptr<scrap::gl::Shader> fragment_shader);
  // Instructs OpenGL to use this program and enables vertex attributes.
  void Begin();
  // Discards the current GL program and disables vertex attributes.
  void End();

  // Basic shader properties
  void SetPositionPointer(uint32_t buffer, uint32_t offset, uint32_t stride);
  void SetUVMapPointer(uint32_t buffer, uint32_t offset, uint32_t stride);
  void SetMVPMatrix(const glm::mat4 &mvp);
  void SetTexture(uint32_t texture);
  
  // Custom shader properties
  void SetUniform(const char *name, int value);
  void SetUniform(const char *name, float value);
  void SetVertexAttribPointer(uint32_t index, int32_t size, int32_t type,
                              bool normalized, uint32_t stride,
                              const void *pointer);

 private:
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  uint32_t program_;
  uint32_t u_mvp_;
  uint32_t u_tex_;
  uint32_t a_pos_;
  uint32_t a_uv_;

};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_PROGRAM_H_
