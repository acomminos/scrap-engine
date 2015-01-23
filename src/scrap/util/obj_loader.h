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
#include "scrap/gl/model.h"

// A wavefront .obj file loader with support for vertex mapping and UV
// coordinates.
namespace scrap {
namespace util {
namespace OBJLoader {

// x, y, z, optional w
static const std::regex kVertexRegex =
    std::regex(R"((\f+)\w+(\f+)\w+(\f+)(?:\w+(\f+))?)");
// v, optional vt, optional vn
static const std::regex kFaceRegex =
    std::regex(R"((\d+)(?:\/(\d+)?(?:\/(\d+))?)?)");

// Loads the OBJ data from the provided input stream into the model given
// Returns true if the operation was a success.
bool Parse(std::istream& in, gl::Model &model) {
    std::string type;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<gl::Element> elements;
    //std::vector<int> indices;
    while (!in.eof()) {
        std::getline(in, type, ' ');
        if (type.compare("v") == 0) {
            GLfloat x, y, z;
            in >> x;
            in >> y;
            in >> z;
            vertices.push_back({x, y, z});
            // TODO(andrew): support for w coordinate?
        } else if (type.compare("vt") == 0) {
            GLfloat u, v;
            in >> u;
            in >> v;
            uvs.push_back(glm::vec2(u, v));
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

            glm::vec3 &vertex = vertices[v];
            glm::vec2 &uv = uvs[vt];
            elements.push_back((gl::Element){vertex, glm::vec3(), uv});
        } else if (type.compare("\\") == 0 || type.compare("\n") == 0) {
            // Ignore newline
        } else {
            printf("Unknown delimiter %s", type.c_str());
        }
skipline:
        char next;
        do {
            next = in.get();
        } while (next != '\n' && next != '\\');
    }
    model.set_elements(elements.data(), elements.size());
}

}  // namespace OBJLoader
}  // namespace util
}  // namespace scrap

#endif  // SRC_SCRAP_UTIL_OBJ_LOADER_H_
