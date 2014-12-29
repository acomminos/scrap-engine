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

#include "scrap/scene/model_scene.h"
#include <iterator>
#include <cassert>
#include "scrap/gl/gl_config.h"
#include "scrap/engine.h"

scrap::ModelScene::ModelScene() {
}

void scrap::ModelScene::OnShow() {
    renderer_ = new Renderer(scrap::engine::Width(), scrap::engine::Height());
}

void scrap::ModelScene::Render() {
    assert(renderer_);  // if this throws, it's a scene lifecycle issue
    renderer_->Render(*this);
}

void scrap::ModelScene::OnHide() {
    delete renderer_;
}

void scrap::ModelScene::OnSizeChange(int width, int height) {
    active_camera_->set_ratio((float)width/(float)height);
    renderer_->Resize(width, height);
}
