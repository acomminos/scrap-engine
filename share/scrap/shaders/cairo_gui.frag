#version 100
uniform sampler2D u_tex;

in vec2 v_texcoord;

void main() {
    vec4 color = texture2D(u_tex, v_texcoord);
    color.rgb /= color.a;
    gl_FragColor.zyxw = color;
}
