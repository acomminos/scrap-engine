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

#ifndef SRC_SCRAP_GUI_COORD_H_
#define SRC_SCRAP_GUI_COORD_H_

#include "scrap/scene.h"
#include "scrap/engine.h"

namespace scrap {
namespace gui {

// An abstract 1d coordinate that can be subclassed to change depending on the
// game state.
class Coord {
    // Returns the absolute value relative to the top left (0,0).
    virtual int GetAbsolute(const Scene &scene) const = 0;
};

// Absolute coordinate relative to the origin.
class AbsoluteCoord : public Coord {
 public:
  AbsoluteCoord(int val) : val_(val) {}
  int GetAbsolute(const Scene &scene) const override { return val_; }
 private:
  int val_;
};

// Coordinate relative to an edge of the screen.
class EdgeCoord : public Coord {
 public:
  typedef enum {
      TOP,
      BOTTOM,
      LEFT,
      RIGHT
  } Edge;
  EdgeCoord(Edge edge, int offset) : edge_(edge), offset_(offset) {}
  virtual int GetAbsolute(const Scene &scene) const override {
    switch (edge_) {
      case TOP:
      case LEFT:
        return offset_;
      case RIGHT:
        return engine::Width() - offset_;
      case BOTTOM:
        return engine::Height() - offset_;
    }
  }
  Edge edge() { return edge_; }
 private:
  Edge edge_;
  int offset_;
};

}  // namespace gui
}  // namespace scrap

#endif  // SRC_SCRAP_GUI_COORD_H_
