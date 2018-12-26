#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 vertexColor;

void main()
{
	gl_position = vec4(aPos, 1.0);
	vertexColor = aColor;
	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}