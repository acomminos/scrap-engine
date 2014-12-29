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

#ifndef SRC_SCRAP_MODEL_H_
#define SRC_SCRAP_MODEL_H_

#include <cstdint>
#include <vector>
#include "scrap/gl/gl_config.h"

namespace scrap {
namespace gl {

// A vertex described by (x,y,z).
typedef struct {
    GLfloat x, y, z;
} Vertex;

// A tuple of texture coordinates (u,v).
typedef struct {
    GLfloat u, v;
} UV;

// A vertex with texture coordinates.
typedef struct {
    Vertex vertex;
    UV uv;
} Element;

// A model assignable to a Doodad. Contains vertex data in an element buffer.
// See gl::Element for GL buffer data layout.
// Uses the RAII model for OpenGL buffer allocation.
class Model {
 public:
  Model(const Element *elements, GLuint num_elements);
  ~Model();
  // Loads the given elements into the model's VBO.
  void set_elements(const Element *elements, GLuint num_elements);
  GLuint num_vertices() { return num_vertices_; }
  GLuint array_buffer() { return array_buffer_; }
  GLuint element_buffer() { return element_buffer_; }
 private:
  GLuint num_vertices_;
  GLuint array_buffer_;
  GLuint element_buffer_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_MODEL_H_
