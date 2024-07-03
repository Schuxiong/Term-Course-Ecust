#version 330 core

in vec2 fragTexCoord;

out vec4 fragColor;

uniform sampler2D textureSampler; // Assuming you use a texture

void main() {
    fragColor = texture(textureSampler, fragTexCoord);
}
