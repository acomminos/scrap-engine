#ifndef SCRAP_GL_SHADER_PROGRAM_
#define SCRAP_GL_SHADER_PROGRAM_

#include <string>

#include "gl/vertex_shader.h"
#include "gl/fragment_shader.h"

namespace scrap {
namespace gl {

class Program {
  public:
    // Registers a new shader program with OpenGL.
    ShaderProgram(VertexShader vertex_shader, FragmentShader fragment_shader);
    ~ShaderProgram();
  private:
    VertexShader vertex_shader_;
    FragmentShader fragment_shader_;
    uint32_t program_;
};

} // gl
} // scrap

#endif // SCRAP_GL_SHADER_PROGRAM_
