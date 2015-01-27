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

#include "scrap/gui/cairo_renderer.h"

// Format: GL_TRIANGLE_STRIP { x, y, u, v }
static GLfloat const kVertexData[] = {
    1.0f, 1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 0.0f, 1.0f,
    1.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, 1.0f, 0.0f
};

static std::string const kVertexShader =
    "#version 100\n"
    "attribute vec2 a_pos;\n"
    "attribute vec2 a_uv;\n"
    "varying vec2 v_texcoord;\n"
    "void main(void) {\n"
    "    v_texcoord = a_uv;\n"
    "    gl_Position = vec4(a_pos, -1, 1);\n"
    "}";

static std::string const kFragmentShader =
    "#version 100\n"
    "precision mediump float;\n"
    "uniform sampler2D u_tex;\n"
    "varying vec2 v_texcoord;\n"
    "void main(void) {\n"
    "    vec4 colour = texture2D(u_tex, v_texcoord);\n"
    "    colour.rgb /= colour.a;\n"
    "    gl_FragColor.zyxw = colour;\n"
    "}";

// FIXME(andrew): do less work in constructor.
scrap::gui::CairoRenderer::CairoRenderer(GLsizei width, GLsizei height) :
        context_(nullptr), surface_(nullptr) {
    Resize(width, height);

    // TODO(andrew): pass program in?
    gl::Shader vertShader(gl::ShaderType::VertexShader);
    vertShader.Compile(kVertexShader);

    gl::Shader fragShader(gl::ShaderType::FragmentShader);
    fragShader.Compile(kFragmentShader);

    program_.Link(vertShader, fragShader);
    assert(program_.is_linked());

    glGenBuffers(1, &buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertexData), kVertexData,
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenTextures(1, &texture_);

    u_tex_ = program_.GetUniformLocation("u_tex");
    a_pos_ = program_.GetAttribLocation("a_pos");
    a_uv_ = program_.GetAttribLocation("a_uv");
}


scrap::gui::CairoRenderer::~CairoRenderer() {
    glDeleteTextures(1, &texture_);
    glDeleteBuffers(1, &buffer_);
    cairo_destroy(context_);
    cairo_surface_destroy(surface_);
}

void scrap::gui::CairoRenderer::Resize(GLsizei width, GLsizei height) {
    if (context_)
        cairo_destroy(context_);
    if (surface_)
        cairo_surface_destroy(surface_);

    // TODO(andrew): surface creation error handling
    surface_ = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    context_ = cairo_create(surface_);
}

void scrap::gui::CairoRenderer::Render() {
    program_.Use();

    glEnableVertexAttribArray(a_pos_);
    glEnableVertexAttribArray(a_uv_);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_);
    unsigned char *data = cairo_image_surface_get_data(surface_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 cairo_image_surface_get_width(surface_),
                 cairo_image_surface_get_height(surface_), 
                 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)data);
    glUniform1i(u_tex_, 0);

    glBindBuffer(GL_ARRAY_BUFFER, buffer_);
    glVertexAttribPointer(a_pos_, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),
                          NULL);
    glVertexAttribPointer(a_uv_, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),
                          (GLvoid*)(2 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(a_pos_);
    glDisableVertexAttribArray(a_uv_);
}
