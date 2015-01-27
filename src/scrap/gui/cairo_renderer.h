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

#ifndef SRC_SCRAP_GUI_CAIRO_RENDERER_H_
#define SRC_SCRAP_GUI_CAIRO_RENDERER_H_

#include <cairo/cairo.h>
#include "scrap/gl/program.h"

namespace scrap {
namespace gui {  // FIXME(andrew): move to gl namespace

// Uses blending to cleanly draw over existing framebuffer data.
class CairoRenderer {
 public:
  CairoRenderer(GLsizei width, GLsizei height);
  ~CairoRenderer();
  void Resize(GLsizei width, GLsizei height);
  void Render();
  cairo_t* get_context() const { return context_; }
 private:
  gl::Program program_;
  cairo_t *context_;
  cairo_surface_t *surface_;
  GLuint texture_;
  GLuint buffer_;
  GLuint u_tex_;
  GLuint a_pos_;
  GLuint a_uv_;
};

}  // namespace gui
}  // namespace scrap


#endif  // SRC_SCRAP_GUI_CAIRO_RENDERER_H_
