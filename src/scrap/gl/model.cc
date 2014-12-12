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

#include "scrap/gl/model.h"
#include "scrap/gl/gl_config.h"

scrap::gl::Model::Model(const float *vertices, int num_vertices,
             const int *elements, int num_elements,
             const float *uv,
             void *texture, int width, int height) :
             num_vertices_(num_vertices) {
    // TODO(andrew): Models with animations (changing vertex data) shouldn't
    // use STATIC_DRAW. Make this a configurable option.
    glGenBuffers(1, &array_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_);
    glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &element_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * num_vertices * sizeof(float),
                 elements, GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
    glBufferData(GL_ARRAY_BUFFER, 2 * num_vertices * sizeof(float),
                 uv, GL_STATIC_DRAW);

    glBindBuffer(0, GL_ARRAY_BUFFER);
    glBindBuffer(0, GL_ELEMENT_ARRAY_BUFFER);
}

scrap::gl::Model::~Model() {
    glDeleteBuffers(1, &array_buffer_);
    glDeleteBuffers(1, &element_buffer_);
    glDeleteBuffers(1, &uv_buffer_);
}
