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

#include <archive.h>
#include "world_loader.h"

#define BLOCK_SIZE 4096

salvage::World salvage::world_loader::LoadFromTar(std::string path) {
    struct archive *archive = archive_read_new();
    if (!archive_read_open_filename(archive, path.c_str(), BLOCK_SIZE)) {
        // TODO(andrew): error handling
    }
    // TODO(andrew): parse archive, get prefabs, doodads
    return World();
}
