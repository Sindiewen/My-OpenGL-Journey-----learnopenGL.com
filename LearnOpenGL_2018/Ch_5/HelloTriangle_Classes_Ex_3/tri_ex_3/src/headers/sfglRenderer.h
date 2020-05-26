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

	unsigned int VBOs[2];	// Initializes the variable to store the current buffer - array for each triangle
	unsigned int VAOs[2];	// Initializes the Vertex array object - array for each triangle


	// Vertices variables

	// drawing triangles
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

	/////////////////////
	// Shader variables
	/////////////////////

	int shaderProgram[2];	// creates shader program object - 0 = orange, 1 = yellow
	

	// -------------------------------------------
	// Private functions

	// Render shapes
	void setupTwoSeparateTrianglesToRender();

	void renderTriangle();

	/////////////////////
	// Main GL Renderer
	/////////////////////

	void glUpdate(); 		// Updates the gl renderer
	void processInput();	// glfw Input Checks	


};


#endif
