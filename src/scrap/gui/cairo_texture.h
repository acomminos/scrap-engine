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

#ifndef SRC_SCRAP_GUI_CAIRO_TEXTURE_H_
#define SRC_SCRAP_GUI_CAIRO_TEXTURE_H_

#include <cairo/cairo.h>
#include "scrap/gl/gl_config.h"
#include "scrap/gl/texture.h"

namespace scrap {
namespace gui {

// A Cairo surface that renders onto an OpenGL texture.
// The Cairo surface is used to manipulate client-side texture data that is
// loaded onto the video card with CopyTexture().
class CairoTexture {
 public:
  CairoTexture(GLsizei width, GLsizei height);
  ~CairoTexture();
  // Copies the current image to the gl::Texture.
  void CopyTexture();
  cairo_surface_t* surface() const { return surface_; }
  const gl::Texture& texture() const { return texture_; }
 private:
  cairo_surface_t *surface_;
  gl::Texture texture_;
  GLsizei width_;
  GLsizei height_;
};

}  // namespace gui
}  // namespace scrap

#endif  // SRC_SCRAP_GUI_CAIRO_TEXTURE_H_
