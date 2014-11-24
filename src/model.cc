#include "model.h"
#include "gl/gl_config.h"

Model::Model(const float *vertices, const float *uv, int num_vertices,
             const char *texture) {
    // TODO(andrew): Models with animations (changing vertex data) shouldn't
    // use STATIC_DRAW. Make this a configurable option.
    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, num_vertices * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
    glBufferData(GL_ARRAY_BUFFER, num_vertices * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(0, GL_ARRAY_BUFFER);

    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, texture);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Model::~Model() {
    glDeleteBuffers(1, &buffer_);
    glDeleteBuffers(1, &uv_buffer_);
    glDeleteTextures(1, &texture_);
}
