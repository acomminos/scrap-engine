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

#include <list>
#include <memory>
#include "scrap/gui/drawable.h"

namespace scrap {
namespace gui {

// A drawable that encapsulates other drawables.
// Child drawables are drawn relative to the group's bounding box.
class DrawableGroup : public Drawable {
 public:
  void draw(cairo_t *ctx) override;
  void add_child(std::shared_ptr<Drawable> child) { children_.push_back(child); };
  const std::list<std::shared_ptr<Drawable>>& get_children() { return children_; };
 private:
  std::list<std::shared_ptr<Drawable>> children_;
};

}  // namespace gui
}  // namespace scrap
