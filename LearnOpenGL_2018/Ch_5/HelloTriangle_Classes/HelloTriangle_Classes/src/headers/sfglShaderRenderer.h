#pragma once
#ifndef SFGLSHADERRENDERER_H
#define SFGLSHADERRENDERER_H

// Preprocessor directives
#include "glPreprocessors.h"

class sfglShaderRenderer
{
public:
	// -------------------------------------
	// Class Constructor
	sfglShaderRenderer();

	// --------------------------------------
	// Class Functions
	void assignShaderSource(const char* vertexSource, const char* fragmentSource);
	void compileShaders();
	void createShaderProgram(int &shaderProgram);

	

private:
	// ----------------------------------
	// Private variables
	unsigned int vertexShader;			// id reference to the created vertex shader
	unsigned int fragmentShader;		// id reference to the created fragment shader

	// Shader source code
	const char* vertexShaderSource;		// Stores the source code for the vertex shader
	const char* fragmentShaderSource;	// Stores the source code for the fragment shader


	// ----------------------------------------
	// Private class functions
	void shaderCompileSuccessCheckVertex();
	void shaderCompileSuccessCheckFragment();
	void shaderLinkingSuccessCheck(int &shaderProgram);
};


#endif
