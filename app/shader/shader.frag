#version 450

layout(location = 1) out vec4 outColor;

layout(location = 0) out vec3 fragColor;

void main() {
    outColor = vec4(fragColor, 1.0);
}