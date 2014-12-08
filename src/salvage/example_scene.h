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

#ifndef SRC_SALVAGE_EXAMPLE_SCENE_H_
#define SRC_SALVAGE_EXAMPLE_SCENE_H_

#include <cmath>
#include "scrap/scene/model_scene.h"

namespace salvage {

class ExampleScene : public scrap::ModelScene {
 public:
  ExampleScene();
  virtual void Update(double delta_time);
  virtual void Render();
  virtual void OnSizeChange(int width, int height);

  virtual void OnMouseButton(int button, int action, int mods);
  virtual void OnMouseScroll(double dx, double dy);
  virtual void OnMouseMove(double x, double y);
  virtual void OnMouseEnter();
  virtual void OnMouseLeave();
  virtual void OnKey(int key, int scancode, int action, int mods);

 private:
  const float theta_velocity_ = M_PI/2;  // pi/2 rad/s
  float theta_;
  float r_;
};

}  // namespace salvage

#endif  // SRC_SALVAGE_EXAMPLE_SCENE_H_
