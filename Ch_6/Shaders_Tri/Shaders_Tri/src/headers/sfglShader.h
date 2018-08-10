#pragma once
#ifndef SFGLSHADER_H
#define SFGLSHADER_H

// Preprocessor directives
#include "glPreprocessors.h"

class sfglShader
{
public:
	// -------------------------------------
	// Class Constructor
	sfglShader();
	sfglShader(const char* vertexPath, const char* fragPath);

	// --------------------------------------
	// Class Functions
	void assignShaderSource(const char* vertexPath, const char* fragPath);
	void compileShaders();
	void createShaderProgram();
	void UseShader();

	// --------------------------------------
	// Shader Uniform setters
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, int value) const;

	// Defines and sets uniform
	void definesShaderUniform();

	// Public variables
	int ShaderProgram;	// ID to the shader Program reference

	

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

	// Compiles and links shaders
	void shaderCompileSuccessCheckVertex();
	void shaderCompileSuccessCheckFragment();
	void shaderLinkingSuccessCheck();
};


#endif
