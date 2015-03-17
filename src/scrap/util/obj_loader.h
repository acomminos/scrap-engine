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

#ifndef SRC_SCRAP_UTIL_OBJ_LOADER_H_
#define SRC_SCRAP_UTIL_OBJ_LOADER_H_

#include <istream>
#include "scrap/gl/model.h"

// A wavefront .obj file loader with support for vertex mapping and UV
// coordinates.
namespace scrap {
namespace util {
namespace OBJLoader {

// Loads the OBJ data from the provided input stream into a new model.
// Uses a singular GL buffer for vertex data. Buffer data is stored according
// to the buffer_usage enumerated constant.
gl::Model Parse(std::istream& in, GLenum buffer_usage);

}  // namespace OBJLoader
}  // namespace util
}  // namespace scrap

#endif  // SRC_SCRAP_UTIL_OBJ_LOADER_H_
