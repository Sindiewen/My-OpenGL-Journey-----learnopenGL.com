#pragma once
#ifndef SFGLRENDERER_H
#define SFGLRENDERER_H

// Preprocessor directives
#include "glPreprocessors.h"
#include "sfglShader.h"

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
	sfglShader shader;	// Reference to the shader class

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

	float oneTriVertColor[18] =
	{
		// Verticies		// Colors
		0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	// Left
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,	// Right
		0.0f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f,	// Top
	};

	float twoTriRectVert[18] =
	{

		// First triangle
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, 0.5f, 0.0f,	// top left
		// 2nd triangle
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};

	float twoTriSbSVerts[18] =
	{
		// First triangle
		-0.9f, -0.5f, 0.0f, // left
		-0.0f, -0.5f, 0.0f, // right
		-0.45f, 0.5f, 0.0f, // top
		// second triangle
		0.0f, -0.5f, 0.0f, // left
		0.9f, -0.5f, 0.0f, // right
		0.45f, 0.5f, 0.0f, // top
	};

	// First triangle
	float triOneVerts[9] =
	{
		
		-0.9f, -0.5f, 0.0f, // left
		-0.0f, -0.5f, 0.0f, // right
		-0.45f, 0.5f, 0.0f, // top
	};

	// second triangle
	float triTwoVerts[9] =
	{
		
		0.0f, -0.5f, 0.0f, // left
		0.9f, -0.5f, 0.0f, // right
		0.45f, 0.5f, 0.0f, // top
	};

	// Drawing rect
	float rectVertices [12] =
	{
		0.5f, 0.5f, 0.0f,	// top right
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f	// top left
	};

	unsigned int indices[6] =	// We start from 0
	{
		0, 1, 3,	// First triangle
		1, 2, 3 	// Second triangle
	};

	/////////////////////
	// Shader variables
	/////////////////////

	//const char* vertexShaderSource =
		//"vertex.vert";
	//const char* fragmentShaderSource =
		//"fragment.frag";

	// Relative to the executable directory
	//const char* vertexShaderPath = "shader.vs";
	//const char* fragmentShaderPath = "shader.fs";
	//const char* shaderPath = "basic.shader";

	// For debugging - relative to the project directory where the *.vcsproj file is location
	const char* vertexShaderPath = "src/shaders/shader.vs";		
	const char* fragmentShaderPath = "src/shaders/shader.fs";
	//const char* shaderPath = "src/shaders/basic.shader";
	

	// -------------------------------------------
	// Private functions

	// Render shapes
	void setupTriangleRender();
	void setupTriangleRenderColorVertex();
	void setupRectRenderer();

	void renderTriangleSingle();
	void renderTriangleDouble();
	void renderRectSingle();

	/////////////////////
	// Main GL Renderer
	/////////////////////

	void glUpdate(); 		// Updates the gl renderer
	void processInput();	// glfw Input Checks	


};


#endif
