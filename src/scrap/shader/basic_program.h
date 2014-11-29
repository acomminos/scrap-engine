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

#ifndef SRC_SCRAP_SHADER_BASIC_PROGRAM_H_
#define SRC_SCRAP_SHADER_BASIC_PROGRAM_H_

#include "scrap/gl/program.h"

namespace scrap {
namespace shader {

// A basic OpenGL shader program with support for primitive drawing, UV
// textures, and transforms.
class BasicProgram : public gl::Program {
 public:
  BasicProgram();
  ~BasicProgram();
  virtual void DrawDoodad(ModelScene *scene, Doodad *doodad);
 private:
};

}  // namespace shader
}  // namespace scrap

#endif  // SRC_SCRAP_SHADER_BASIC_PROGRAM_H_
