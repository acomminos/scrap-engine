#version 100
in vec2 a_pos;
in vec2 a_uv;

varying vec2 v_texcoord;

void main(void) {
    gl_Position = a_pos;
    v_texcoord = a_uv;
}
