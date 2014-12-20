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

#ifndef SRC_SCRAP_RENDERER_H_
#define SRC_SCRAP_RENDERER_H_

#include <map>
#include <vector>
#include "scrap/doodad.h"
#include "scrap/camera.h"

namespace scrap {

class Renderer {
 public:
  Renderer();
  ~Renderer();
  void AddDoodad(Doodad &doodad);
  void RemoveDoodad(Doodad &doodad);
  void SetCamera(Camera *camera);
  void Render();
 private:
  Camera *camera_;
  std::map<gl::Program*, std::vector<Doodad*>> doodads_;
};

}  // namespace scrap

#endif  // SRC_SCRAP_RENDERER_H_
