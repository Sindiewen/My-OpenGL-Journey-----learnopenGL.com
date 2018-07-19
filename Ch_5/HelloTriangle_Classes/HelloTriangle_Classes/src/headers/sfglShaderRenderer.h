#pragma once
#ifndef SFGLSHADERRENDERER_H
#define SFGLSHADERRENDERER_H

class shaderRenderer
{
private:
	unsigned int vertexShader;		// id reference to the created vertex shader
	unsigned int fragmentShader;	// id reference to the created fragment shader
	unsigned int shaderProgram;		// id reference to the shader program

	const char* vertexShaderSource;
};


#endif
