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

#include "scrap/model.h"
#include "scrap/gl/gl_config.h"

Model::Model(const float *vertices, const float *uv, int num_vertices,
             void *texture) {
    // TODO(andrew): Models with animations (changing vertex data) shouldn't
    // use STATIC_DRAW. Make this a configurable option.
    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
    glBufferData(GL_ARRAY_BUFFER, 2 * num_vertices * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(0, GL_ARRAY_BUFFER);

    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,  texture_);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Model::~Model() {
    glDeleteBuffers(1, &buffer_);
    glDeleteBuffers(1, &uv_buffer_);
    glDeleteTextures(1, &texture_);
}
