#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 fragTexCoord;

uniform mat4 modelViewProjection;

void main() {
    gl_Position = modelViewProjection * vec4(position, 1.0);
    fragTexCoord = texCoord;
}
