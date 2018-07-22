#pragma once
#ifndef SFGLRENDERER_H
#define SFGLRENDERER_H

// Preprocessor directives
#include "glPreprocessors.h"
#include "sfglShaderRenderer.h"

class sfglRenderer
{
public:
	// ----------------------------------------
	// Class constructors
	sfglRenderer();


	// ---------------------------------------
	// public functions
	/////////////////////

	// Sets the window value
	void setWindow(GLFWwindow* window);

	// Initiates the renderer in this class
	void initiateRenderer();


private:
	// -------------------------------------------
	// Private variables
	

	GLFWwindow* window; // reference to the window in the main sfgl class
	sfglShaderRenderer shader;	// Reference to the shader class

	unsigned int VBO;	// Initializes the variable to store the current buffer
	unsigned int VAO;	// Initializes the Vertex array object
	unsigned int EBO;	// Initializes the element buffer object


	// Vertices variables

	// drawing triangles
	float oneTrivertices[9] = // Triangle
	{
		-0.5f, -0.5f, 0.0f, // left
		0.5f, -0.5f, 0.0f,	// right
		0.0f, 0.5f, 0.0f,	// top
	};

	float twoTriRectVert[18] =
	{
		// First triangle
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, 0.5f, 0.0f,	// top left
		// 2nd triangle
		0.5f, -0.5f, 0.0f,	// bottom right
		0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};

	// Drawing rect
	float vertices [12] =
	{
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};

	unsigned int indices[6] =	// We start from 0
	{
		0, 1, 2,	// First triangle
		2, 1, 3 	// Second triangle
	};

	/////////////////////
	// Shader variables
	/////////////////////
	int shaderProgram;	// creates shader program object
	

	// shader sources
	// Use const char to store shader source
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
			"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
			"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}";
	

	// -------------------------------------------
	// Private functions

	// Render shapes
	void setupTriangleSingleRender();
	void setupRectRenderer();

	void renderTriangleSingle();
	void renderRectSingle();

	/////////////////////
	// Main GL Renderer
	/////////////////////

	void glUpdate(); 		// Updates the gl renderer
	void processInput();	// glfw Input Checks	


};


#endif
