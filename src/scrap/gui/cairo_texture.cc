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

#include "scrap/gui/cairo_texture.h"

scrap::gui::CairoTexture::CairoTexture(GLsizei width, GLsizei height) :
    width_(width), height_(height) {
    surface_ = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
}

scrap::gui::CairoTexture::~CairoTexture() {
    cairo_surface_destroy(surface_);
}

void scrap::gui::CairoTexture::CopyTexture() {
    unsigned char *data = cairo_image_surface_get_data(surface_);
    texture_.SetData(GL_UNSIGNED_BYTE, data, width_, height_);
}
