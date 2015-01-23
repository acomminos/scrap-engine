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

scrap::gl::Model::Model() {
}

scrap::gl::Model::~Model() {
    ResetVertexData();
}

void scrap::gl::Model::SetVertexData(const glm::vec3 *positions,
                                     const glm::vec3 *normals,
                                     const glm::vec2 *uvs,
                                     const glm::vec4 *colours,
                                     GLsizei num_vertices) {
    ResetVertexData();

    // TODO(andrew): allocate buffers for vertex data
}

void scrap::gl::Model::ResetVertexData() {
    if (position_buffer_.enabled) {
        glDeleteBuffers(1, &position_buffer_.buffer);
        position_buffer_.enabled = false;
    }
    if (normal_buffer_.enabled) {
        glDeleteBuffers(1, &normal_buffer_.buffer);
        normal_buffer_.enabled = false;
    }
    if (uv_buffer_.enabled) {
        glDeleteBuffers(1, &uv_buffer_.buffer);
        uv_buffer_.enabled = false;
    }
    if (colour_buffer_.enabled) {
        glDeleteBuffers(1, &colour_buffer_.buffer);
        colour_buffer_.enabled = false;
    }
}
