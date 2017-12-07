#version 330 core
out vec4 FragColor;

in vec3 vert_color;
in vec2 vert_texcoord;

uniform sampler2D u_texture;

void main()
{
    FragColor = texture(u_texture, vert_texcoord);
}
