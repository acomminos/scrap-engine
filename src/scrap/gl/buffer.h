// Copyright © 2015 Andrew Comminos <andrew@morlunk.com>
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

#ifndef SRC_SCRAP_GL_BUFFER_H_
#define SRC_SCRAP_GL_BUFFER_H_

#include <vector>
#include "scrap/gl/gl_config.h"

namespace scrap {
namespace gl {

// An RAII wrapper for an OpenGL buffer.
// Provides facilities for retrieving vertex attrib data.
class Buffer {
 public:
  Buffer(GLuint buffer) : buffer_(buffer) {};
  Buffer();
  ~Buffer();
  GLuint buffer() const { return buffer_; }
 private:
  GLuint buffer_;
};

}  // namespace gl
}  // namespace scrap

#endif  // SRC_SCRAP_GL_BUFFER_H_
