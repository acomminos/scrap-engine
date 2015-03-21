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
#include <iostream>
#include <sstream>
#include "scrap/engine.h"
#include "scrap/util/obj_loader.h"

salvage::ExampleScene::ExampleScene() : ModelScene(),
                                        r_(100.0f) {
}

void salvage::ExampleScene::Update(double delta_time) {
    theta_ = fmod(theta_ + (theta_velocity_ * delta_time), 2*M_PI);
    delta_t_ = delta_time;
    // printf("dt: %f, t: %fpi\n", delta_time, theta_/M_PI);
}

void salvage::ExampleScene::DrawGUI(cairo_t *ctx) {
    static char buf[100];
    int width = scrap::engine::Width();
    int height = scrap::engine::Height();

    // Draw FPS
    cairo_set_source_rgba(ctx, 1.0f, 1.0f, 1.0f, 1.0f);
    cairo_move_to(ctx, 50, 50);
    std::ostringstream fps;
    fps << "FPS: " << 1.0f/delta_t_;
    cairo_show_text(ctx, fps.str().c_str());

    // Example rectangle
    cairo_set_source_rgba(ctx, 1.0f, 0.0f, 0.0f, 1.0f);
    cairo_rectangle(ctx, width/2, height/2, r_*cos(theta_), r_*sin(theta_));
    cairo_fill(ctx);
}

void salvage::ExampleScene::OnMouseButton(int button, int action, int mods) {
}

void salvage::ExampleScene::OnMouseScroll(double dx, double dy) {
}

void salvage::ExampleScene::OnMouseMove(double x, double y) {
    int center_x = scrap::engine::Width() / 2;
    int center_y = scrap::engine::Height() / 2;
    r_ = sqrt(pow(x - center_x, 2) + pow(y - center_y, 2));
}

void salvage::ExampleScene::OnMouseEnter() {
}

void salvage::ExampleScene::OnMouseLeave() {
}

void salvage::ExampleScene::OnKey(int key, int scancode, int action, int mods) {
    printf("Key event (key: %d, scancode: %d, action: %d, mods: %d)\n",
           key, scancode, action, mods);
}
