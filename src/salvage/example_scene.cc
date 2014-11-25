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

#include "salvage/example_scene.h"
#include <cstdio>
#include "scrap/engine.h"

void salvage::ExampleScene::Update(double delta_time) {
    theta_ = fmod(theta_ + (theta_velocity_ * delta_time), 2*M_PI);
    // printf("dt: %f, t: %fpi\n", delta_time, theta_/M_PI);
}

void salvage::ExampleScene::Render() {
    int x = r_ * cos(theta_);
    int y = r_ * sin(theta_);
}

void salvage::ExampleScene::OnMouseButton(int button, int action, int mods) {
}

void salvage::ExampleScene::OnMouseScroll(double dx, double dy) {
}

void salvage::ExampleScene::OnMouseMove(double x, double y) {
}

void salvage::ExampleScene::OnMouseEnter() {
}

void salvage::ExampleScene::OnMouseLeave() {
}

void salvage::ExampleScene::OnKey(int key, int scancode, int action, int mods) {
    printf("Key event (key: %d, scancode: %d, action: %d, mods: %d)\n",
           key, scancode, action, mods);
}
