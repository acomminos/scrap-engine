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
#include <regex>
#include "scrap/model.h"

// A wavefront .obj file loader with support for vertex mapping and UV
// coordinates.
namespace scrap {
namespace util {
namespace OBJLoader {

// x, y, z, optional w
static const std::regex kVertexRegex = "(\f+)\w+(\f+)\w+(\f+)(?:\w+(\f+))?";
// v, optional vt, optional vn
static const std::regex kFaceRegex = "(\d+)(?:\/(\d+)?(?:\/(\d+))?)?";

// Parses the OBJ data provided by the given stream.
Model* Parse(std::istream& in) {
    in.flags(std::skipws);
    std::string type;
    std::vector<int> elements;
    std::vector<float> vertices;
    std::vector<float> uv;
    while (!in.eof()) {
        std::getline(in, type, ' ');
        if (type.equals("v")) {
            float x, y, z;
            in >> x;
            in >> y;
            in >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            // TODO(andrew): support for w coordinate?
        } else if (type.equals("vt")) {
            float u, v;
            in >> u;
            in >> v;
            uv.push_back(u);
            uv.push_back(v);
        } else if (type.equals("f")) {
            float v, vt, vn;
            std::smatch results;
            std::regex_match(kFaceRegex, results);

        }
    }
    Model *model = new Model();
}

}  // namespace OBJLoader
}  // namespace util
}  // namespace scrap

#endif  // SRC_SCRAP_UTIL_OBJ_LOADER_H_
