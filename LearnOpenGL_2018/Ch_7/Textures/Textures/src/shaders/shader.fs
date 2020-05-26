#version 330 core
out vec4 FragColor;
in vec3 vertexColor;
in vec3 vertexPosition;

void main()
{
    //FragColor = vec4(vertexColor, 1.0);
	FragColor = vec4(vertexPosition, 1.0);
}
// Bottom left of triangle is black because of the position of that vertex is < 0