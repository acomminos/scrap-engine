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

#include <cairo/cairo.h>

namespace scrap {
namespace gui {

// An abstract base class for 2D views drawn with Cairo to be displayed on the
// screen.
class Drawable {
 public:
  // Draws in the given Cairo context.
  virtual void draw(cairo_t *ctx);

  void set_x(int x) { x_ = x; }
  void set_y(int y) { y_ = y; }
  void set_width(int width) { width_ = width; }
  void set_height(int height) { height_ = height; }
  int x() { return x_; }
  int y() { return y_; }
  int width() { return width_; }
  int height() { return height_; }
 protected:
  int x_, y_, width_, height_;
};

}  // namespace gui
}  // namespace scrap
