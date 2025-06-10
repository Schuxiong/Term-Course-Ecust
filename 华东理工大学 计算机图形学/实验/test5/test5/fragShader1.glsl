#version 430 core

in vec2 TexCoord;
out vec4 FragColor;

void main() {
    FragColor = vec4(TexCoord, 0.0, 1.0); // Modify this to your actual fragment shader logic
}
