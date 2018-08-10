#version 330 core
out vec4 FragColor;
in vec3 vertexColor;

void main()
{
	FragColor = vertexColor;
}