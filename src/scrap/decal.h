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

#ifndef SRC_SCRAP_DECAL_H_
#define SRC_SCRAP_DECAL_H_

#include "gl/gl_config.h"
#include "gl/texture.h"

namespace scrap {

// A decal is a 2d object in screen coordinates. It is rendered in the GUI
// layer.
class Decal {
 public:
  // Creates a new decal backed by the given texture.
  Decal(const gl::Texture &texture, GLfloat x, GLfloat y, GLfloat width,
        GLfloat height) : texture_(texture), x_(x), y_(y), width_(width),
        height_(height) {};
  // Creates a new decal backed by the given texture using the size of the
  // backing texture.
  Decal(const gl::Texture &texture, GLfloat x, GLfloat y) :
    Decal(texture, x, y, texture.width(), texture.height()) {};
  GLfloat x() const { return x_; }
  void set_x(GLfloat x) { x_ = x; }
  GLfloat y() const { return y_; }
  void set_y(GLfloat y) { y_ = y; }
  GLfloat width() const { return width_; }
  void set_width(GLfloat width) { width_ = width; }
  GLfloat height() const { return height_; }
  void set_height(GLfloat height) { height_ = height; };

 private:
  const gl::Texture &texture_;
  GLfloat x_;
  GLfloat y_;
  GLfloat width_;
  GLfloat height_;
};

}  // namespace scrap


#endif  // SRC_SCRAP_DECAL_H_
