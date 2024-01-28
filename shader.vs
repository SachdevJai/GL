#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

uniform mat4 camMatrix;
uniform mat4 modelMatrix;

void main()
{
   gl_Position = camMatrix * modelMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
   color = aColor;
}