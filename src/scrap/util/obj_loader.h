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
#include <cassert>
#include "scrap/model.h"

// A wavefront .obj file loader with support for vertex mapping and UV
// coordinates.
namespace scrap {
namespace util {
namespace OBJLoader {

// A vertex described by (x,y,z).
// TODO(andrew): move?
typedef struct {
    float x, y, z;
} Vertex;

// A tuple of texture coordinates (u,v).
typedef struct {
    float u, v;
} UV;

// A vertex with texture coordinates.
typedef struct {
    Vertex &vertex;
    UV &uv;
} Element;

// x, y, z, optional w
static const std::regex kVertexRegex = std::regex("(\f+)\w+(\f+)\w+(\f+)(?:\w+(\f+))?");
// v, optional vt, optional vn
static const std::regex kFaceRegex = std::regex("(\d+)(?:\/(\d+)?(?:\/(\d+))?)?");

// Parses the OBJ data provided by the given stream.
Model* Parse(std::istream& in) {
    std::string type;
    std::vector<Vertex> vertices;
    std::vector<UV> uvs;
    std::vector<Element> elements;
    while (!in.eof()) {
        std::getline(in, type, ' ');
        if (type.compare("v") == 0) {
            float x, y, z;
            in >> x;
            in >> y;
            in >> z;
            vertices.push_back({x, y, z});
            // TODO(andrew): support for w coordinate?
        } else if (type.compare("vt") == 0) {
            float u, v;
            in >> u;
            in >> v;
            uvs.push_back({u, v});
        } else if (type.compare("f") == 0) {
            std::string line;
            std::getline(in, line);
            int v, vt, vn;
            std::smatch m;
            std::regex_match(line, m, kFaceRegex);
            if (m.empty())
                assert("No matches found for face regex!");
            else if (m.size() < 2)
                assert("Not enough matches for face line!");
            if (m[1].matched)
                v = atoi(static_cast<std::string>(m[1]).c_str());
            if (m[2].matched)
                vt = atoi(static_cast<std::string>(m[2]).c_str());
            if (m[3].matched)
                vn = atoi(static_cast<std::string>(m[3]).c_str());

            Vertex &vertex = vertices[v];
            UV &uv = uvs[vt];
            elements.push_back({vertex, uv});
        }
    }
    //Model *model = new Model();
}

}  // namespace OBJLoader
}  // namespace util
}  // namespace scrap

#endif  // SRC_SCRAP_UTIL_OBJ_LOADER_H_
