#version 100
uniform mat4 u_mvp;

in vec3 a_pos;
in vec2 a_uv;

out vec2 v_texcoord;

void main(void) {
    gl_Position = u_mvp * a_pos;
    v_texcoord = a_uv;
}
