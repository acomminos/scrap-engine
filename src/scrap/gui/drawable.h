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
#include "scrap/gui/coord.h"

namespace scrap {
namespace gui {

// An abstract base class for 2D views drawn with Cairo to be displayed on the
// screen.
class Drawable {
 public:
  // Draws in the given Cairo context.
  virtual void Draw(cairo_t *ctx) {}
  // Called when the mouse enters the drawable's bounds.
  virtual void OnMouseEnter() {}
  // Called when the mouse is moved within the drawable's bounds.
  virtual void OnMouseMove() {}
  // Called when a mouse button is pressed within the drawable's bounds.
  virtual void OnMouseButton() {}
  // Called when the mouse leaves the drawable's bounds.
  virtual void OnMouseLeave() {}
  // Called when a key is pressed, regardless of whether or not the mouse was
  // within the drawable's bounds.
  // TODO(andrew): implement focus
  virtual void OnKey(int key, int scancode, int action, int mods) {}

  const Coord& top() const { return top_; }
  const Coord& left() const { return left_; }
  const Coord& bottom() const { return bottom_; }
  const Coord& right() const { return right_; }
  void set_top(Coord top) { top_ = top; }
  void set_left(Coord left) { left_ = left; }
  void set_bottom(Coord bottom) { bottom_ = bottom; }
  void set_right(Coord right) { right_ = right; }
 protected:
  Coord top_, left_, bottom_, right_;
};

}  // namespace gui
}  // namespace scrap
