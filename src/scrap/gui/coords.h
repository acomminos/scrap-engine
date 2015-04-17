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

#ifndef SRC_SCRAP_GUI_COORDS_H_
#define SRC_SCRAP_GUI_COORDS_H_

#include "scrap/scene.h"
#include "scrap/engine.h"

namespace scrap {
namespace gui {

// An abstract 2d coordinate that can be subclasses to change depending on the
// game state.
class Coords {
    virtual int GetX(const Scene &scene) const = 0;
    virtual int GetY(const Scene &scene) const = 0;
};

// Absolute coordinates relative to the origin.
class AbsoluteCoords : public Coords {
 public:
  AbsoluteCoords(int x, int y) : x_(x), y_(y) {}
  int GetX(const Scene &scene) const override { return x_; }
  int GetY(const Scene &scene) const override { return y_; }
 private:
  int x_, y_;
};

// Coordinates relative to a corner of the screen.
class GravityCoords : public Coords {
 public:
  typedef enum {
      TOP_LEFT,
      TOP_RIGHT,
      BOTTOM_LEFT,
      BOTTOM_RIGHT
  } Corner;
  GravityCoords(Corner corner, int x, int y) : corner_(corner), x_(x), y_(y) {}
  int GetX(const Scene &scene) const override {
    switch (corner_) {
        case TOP_LEFT:
        case BOTTOM_LEFT:
            return x_;
        case TOP_RIGHT:
        case BOTTOM_RIGHT:
            return engine::Width() - x_;
    }
  }
  int GetY(const Scene &scene) const override {
    switch (corner_) {
        case TOP_LEFT:
        case TOP_RIGHT:
            return y_;
        case BOTTOM_LEFT:
        case BOTTOM_RIGHT:
            return engine::Height() - y_;
    }
  }
 private:
  Corner corner_;
  int x_;
  int y_;
};

}  // namespace gui
}  // namespace scrap

#endif  // SRC_SCRAP_GUI_COORDS_H_
