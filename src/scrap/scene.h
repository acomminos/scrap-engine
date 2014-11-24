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

#ifndef SRC_SCRAP_SCENE_H_
#define SRC_SCRAP_SCENE_H_

namespace scrap {

class Scene {
 public:
  virtual void Update(double delta_time) = 0;
  virtual void Render() = 0;

  virtual void OnMouseButton(int button, int action, int mods) = 0;
  virtual void OnMouseScroll(double dx, double dy) = 0;
  virtual void OnMouseMove(double x, double y) = 0;
  virtual void OnMouseEnter() = 0;
  virtual void OnMouseLeave() = 0;
  virtual void OnKey(int key, int scancode, int action, int mods) = 0;
};

}  // namespace scrap

#endif  // SRC_SCRAP_SCENE_H_
