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
#include <map>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "scrap/gl/gl_config.h"
#include "scrap/gl/program.h"

namespace scrap {
namespace gl {

// A model assignable to a Doodad. Contains vertex data.
// Uses the RAII model for OpenGL buffer allocation.
class Model {
 public:
  Model();
  ~Model();
  // Sets the vertex data for this model, uploading each attribute into video
  // memory.
  void SetVertexData(const AttribBuffer pos_buffer,
                     const AttribBuffer normal_buffer,
                     const AttribBuffer uv_buffer,
                     GLsizei num_vertices);
  void ResetVertexData();
  const AttribBuffer* position_buffer() const { return position_buffer_.get(); }
  const AttribBuffer* normal_buffer() const { return normal_buffer_.get(); }
  const AttribBuffer* uv_buffer() const { return uv_buffer_.get(); }
  const AttribBuffer* colour_buffer() const { return colour_buffer_.get(); }
  GLsizei num_vertices() const { return num_vertices_; }
 private:
  std::unique_ptr<AttribBuffer> position_buffer_;
  std::unique_ptr<AttribBuffer> normal_buffer_;
  std::unique_ptr<AttribBuffer> uv_buffer_;
  std::unique_ptr<AttribBuffer> colour_buffer_;
  GLsizei num_vertices_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_MODEL_H_
