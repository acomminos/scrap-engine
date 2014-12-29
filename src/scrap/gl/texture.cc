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

#include "scrap/gl/texture.h"

scrap::gl::Texture::Texture() {
    glGenTextures(1, &texture_);
}

scrap::gl::Texture::~Texture() {
    glDeleteTextures(1, &texture_);
}

void scrap::gl::Texture::SetData(GLenum type, const GLvoid *data,
                                 GLsizei width, GLsizei height) {
    // TODO(andrew): bind elsewhere
    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, 
                 GL_RGBA, type, data);
    glBindTexture(GL_TEXTURE_2D, 0);

}
