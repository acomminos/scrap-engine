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

#include <string>
#include "world.h"

#ifndef SRC_SALVAGE_WORLD_LOADER_H_
#define SRC_SALVAGE_WORLD_LOADER_H_

namespace salvage {
namespace world_loader {

// Loads the world described by a tarred .salvage file into a new world.
World LoadFromTar(std::string path);

}  // namespace world_loader
}  // namespace salvage

#endif  // SRC_SALVAGE_WORLD_LOADER_H_
