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

#ifndef SCRAP_UTIL_OBJ_LOADER_H_
#define SCRAP_UTIL_OBJ_LOADER_H_

#include <istream>
#include "model.h"

// A wavefront .obj file loader with support for vertex mapping and UV
// coordinates.
namespace scrap {
namespace util {
namespace OBJLoader {

Model* Parse(std::istream& in) {
    std::string type;
    while (!in.eof()) {
        in.get(type, ' ');
        if (type.equals("vt")) {
            float x, y, z;
            in >> x;
            in >> y;
            in >> z;
        }

        // Skip until newline terminator (\ or \n)
        char end;
        do {
            end = in.get();
        } while (end != '\\' && end != '\n')
    }
    Model *model = new Model();
}

}  // namespace OBJLoader
}  // namespace util
}  // namespace scrap
