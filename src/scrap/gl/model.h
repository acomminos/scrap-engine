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

namespace scrap {
namespace gl {

// A model assignable to a Doodad. Contains vertex data in an element buffer.
// Uses the RAII model for OpenGL buffer allocation.
class Model {
 public:
  Model(const float *vertices, int num_vertices, const int *elements,
        int num_elements, const float *uv, void *texture, int width,
        int height);
  ~Model();
  uint32_t num_vertices() { return num_vertices_; }
  uint32_t array_buffer() { return array_buffer_; }
  uint32_t element_buffer() { return element_buffer_; }
  uint32_t uv_buffer() { return uv_buffer_; }
 private:
  uint32_t num_vertices_;
  uint32_t array_buffer_;
  uint32_t element_buffer_;
  uint32_t uv_buffer_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_MODEL_H_
