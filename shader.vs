#version 330 core
layout (location = 0) in vec3 aPos;


out vec3 color;

uniform mat4 camMatrix;
uniform mat4 modelMatrix;
uniform vec3 aColor;
uniform mat4 faceMatrix;

void main()
{
   gl_Position = camMatrix * modelMatrix * faceMatrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
   color = aColor;
}