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

scrap::ModelScene::ModelScene() : camera_(90, 0.5, 100, 1000) {
    auto vert_shader = std::make_shared<gl::Shader>(gl::VertexShader);
    auto frag_shader = std::make_shared<gl::Shader>(gl::FragmentShader);
    // FIXME(andrew): example code
    vert_shader->Compile(
        "#version 100\n"
        "uniform mat4 u_mvp;\n"
        "attribute vec3 a_pos;\n"
        "attribute vec3 a_normal;\n"
        "attribute vec2 a_uv;\n"
        "varying vec2 v_texcoord;\n"
        "void main(void) {\n"
        "   gl_Position = u_mvp * vec4(a_pos, 1.0);\n"
        "   v_texcoord = a_uv;\n"
        "}");
    frag_shader->Compile(
        "#version 100\n"
        "precision mediump float;\n"
        "uniform sampler2D u_tex;\n"
        "varying vec2 v_texcoord;\n"
        "void main() {\n"
        "    vec4 color = texture2D(u_tex, v_texcoord);\n"
        "    gl_FragColor = color;\n"
        "}");

    default_program_ = std::make_shared<gl::Program>();
    default_program_->Link(vert_shader, frag_shader);
    model_renderer_.SetProgram(default_program_);
}

scrap::ModelScene::~ModelScene() {
}

void scrap::ModelScene::OnShow() {
    cairo_renderer_.reset(new gl::CairoRenderer(engine::Width(), engine::Height()));
}

void scrap::ModelScene::Render() {
    assert(cairo_renderer_);
    model_renderer_.Render(*this);

    cairo_renderer_->Clear();
    cairo_t *ctx = cairo_renderer_->get_context();
    cairo_save(ctx);
    DrawGUI(ctx);
    cairo_restore(ctx);
    cairo_renderer_->Render();
}

void scrap::ModelScene::OnHide() {
    cairo_renderer_.release();
}

void scrap::ModelScene::OnSizeChange(int width, int height) {
    camera_.set_ratio((float)width/(float)height);
    cairo_renderer_->Resize(width, height);
}
