#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 vertexColor;	// Sets vertex color variable variable going out to fragment
void main()
{
	// Setting a vector3 into the vector4's constructor. Needs 1 more parameter though as it is a vector4
	gl_Position = vec4(aPos, 1.0);
		
	// Setting vertexColor to aColor
	vertexColor = aColor;

	// Setting the output color for the shader
	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}