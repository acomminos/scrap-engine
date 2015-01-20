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

#ifndef SRC_SCRAP_TEXTURE_H_
#define SRC_SCRAP_TEXTURE_H_

#include "scrap/gl/gl_config.h"

namespace scrap {
namespace gl {

// A wrapper around an RGBA 2D OpenGL texture.
class Texture {
  public:
    Texture();
    ~Texture();
    void SetData(GLenum type, const GLvoid *data, GLsizei width,
                 GLsizei height);
    GLuint texture() const { return texture_; }
    GLsizei width() const { return width_; }
    GLsizei height() const { return height_; }
  private:
    GLuint texture_;
    GLsizei width_;
    GLsizei height_;
};

};  // namespace gl
};  // namespace scrap

#endif  // SRC_SCRAP_TEXTURE_H_
