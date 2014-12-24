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
#include "scrap/gl/gl_config.h"

namespace scrap {
namespace gl {

// A wrapper around a GLSL shader program.
// Uses std::unique_ptr to manage lifecycle of OpenGL state.
class Program {
 public:
  // Registers a new shader program with OpenGL.
  Program();
  ~Program();

  // Attaches the given shaders, and links this program.
  // Returns true if the program was successfully linked.
  bool Link(std::unique_ptr<scrap::gl::Shader> vertex_shader,
            std::unique_ptr<scrap::gl::Shader> fragment_shader);
  bool is_linked() const { return linked_; }
  // Instructs OpenGL to use this program.
  void Use();
  
  GLuint GetUniformLocation(const char *name) const;
  GLuint GetAttribLocation(const char *name) const;
  void SetUniform(GLuint uniform, int value);
  void SetUniform(GLuint uniform, float value);
  void SetVertexAttribPointer(GLuint index, GLsizei size, GLenum type,
                              GLboolean normalized, GLuint stride,
                              const GLvoid *pointer);
 private:
  bool linked_;
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  GLuint program_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_PROGRAM_H_
