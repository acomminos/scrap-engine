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

#include <regex>
#include <cassert>
#include "scrap/gl/gl_config.h"
#include "scrap/util/obj_loader.h"
#include "scrap/gl/program.h"

// x, y, z, optional w
static const std::regex kVertexRegex =
    std::regex(R"((\f+)\w+(\f+)\w+(\f+)(?:\w+(\f+))?)");
// v, optional vt, optional vn
static const std::regex kFaceRegex =
    std::regex(R"((\d+)(?:\/(\d+)?(?:\/(\d+))?)?)");

scrap::gl::Model scrap::util::OBJLoader::Parse(std::istream& in, GLenum buffer_usage) {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };
    std::string type;
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<Vertex> vertices;
    while (!in.eof()) {
        std::getline(in, type, ' ');
        if (type.compare("v") == 0) {
            GLfloat x, y, z;
            in >> x;
            in >> y;
            in >> z;
            positions.push_back(glm::vec3(x, y, z));
            // TODO(andrew): support for w coordinate?
        } else if (type.compare("vt") == 0) {
            GLfloat u, v;
            in >> u;
            in >> v;
            uvs.push_back(glm::vec2(u, v));
        } else if (type.compare("vn") == 0) {
            GLfloat x, y, z;
            in >> x;
            in >> y;
            in >> z;
            normals.push_back(glm::vec3(x, y, z));
        } else if (type.compare("f") == 0) {
            // FIXME(andrew): we assume 3-vertex faces. quads may be given.
            for (int i = 0; i < 3; i++) {
                Vertex vertex;
                std::string vertex_str;
                in >> vertex_str;
                std::smatch m;
                std::regex_match(vertex_str, m, kFaceRegex);
                if (m.empty())
                    assert("No matches found for face regex!");
                else if (m.size() < 2)
                    assert("Not enough matches for face line!");
                if (m[1].matched)
                    vertex.position = positions[std::stoi(m[1])];
                if (m[2].matched)
                    vertex.uv = uvs[std::stoi(m[2])];
                if (m[3].matched)
                    vertex.normal = normals[std::stoi(m[3])];

                vertices.push_back(vertex);
            }
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
    std::shared_ptr<gl::Buffer> buffer = std::make_shared<gl::Buffer>();
    GLuint buffer_idx = buffer->buffer();
    glBindBuffer(GL_ARRAY_BUFFER, buffer_idx);
    glBufferData(GL_ARRAY_BUFFER, vertices.size(), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    gl::AttribBuffer pos_buffer = {
        .size = sizeof(GLfloat) * 3,
        .type = GL_FLOAT,
        .normalized = GL_FALSE,
        .stride = sizeof(GLfloat) * 9,
        .offset = 0,
        .buffer = buffer
    };

    //gl::Model model(pos_buffer, NULL, NULL);
    // TODO(andrew): set model attribute
}
