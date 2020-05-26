#include "headers\sfglShaderRenderer.h"

// ------------------------------------
// Default constructor
sfglShaderRenderer::sfglShaderRenderer()
{
	// default constructor
	// Sets the source code for the shaders
	
	// Sets the source for vertext shader in index 0
	// Note: After compiling, i'll just copy the compiled source to the 2nd vertex shader
	vertexShaderSource[0] = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
			"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}";

	vertexShaderSource[1] = vertexShaderSource[0];

	fragmentShaderSource[0] = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}";

	fragmentShaderSource[1] = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 1.0f, 0.1f, 1.0f);\n"
		"}";


		
}

// Compiles the shader renderer
void sfglShaderRenderer::compileShaders()
{
	/*
	 * 0 = orange
	 * 1 = yellow
	 */
	for (int i = 0; i < 2; i++)
	{
		// Compiles the Vertex Shader - Orange
		vertexShader[i] = glCreateShader(GL_VERTEX_SHADER);			// Tells shader program to create a vertex shader
		glShaderSource(vertexShader[i], 1, &vertexShaderSource[i], NULL);	// Attaching the shader source to the vertex shader
		glCompileShader(vertexShader[i]);							// Compiles the attached vertex shader
		
		// Compiles the fragment shader - Orange
		fragmentShader[i] = glCreateShader(GL_FRAGMENT_SHADER);			// Tells shader program to create fragment shader
		glShaderSource(fragmentShader[i], 1, &fragmentShaderSource[i], NULL);	// Attach the fragment shader source to the fragment shader
		glCompileShader(fragmentShader[i]);								// Compiles the fragment shader
	}
	shaderCompileSuccessCheckVertex();	// Checks to see if both vertex shaders compiles successfully
	shaderCompileSuccessCheckFragment(); // CHecks to see if both fragment shaders compiled successfully
}

// Creates the shader program
void sfglShaderRenderer::createShaderProgram(int shaderProgram[])
{
	// Attach shaders to the shader program
	for (int i = 0; i < 2; i++)
	{
		shaderProgram[i] = glCreateProgram();
		glAttachShader(shaderProgram[i], vertexShader[i]);		// Attaches vertex shader to the shader program
		glAttachShader(shaderProgram[i], fragmentShader[i]);		// Attaches fragment shader to the shader program
		glLinkProgram(shaderProgram[i]);						// Links the shaders to the program
	}
	shaderLinkingSuccessCheck(shaderProgram);			// Checks to see if the shader linking was successful

	// Deletes old shader object as the program was run
	glDeleteShader(vertexShader[0]);
	glDeleteShader(vertexShader[1]);
	glDeleteShader(fragmentShader[0]);
	glDeleteShader(fragmentShader[1]);
}


// --------------------------------------
// Shader Error Checking
//////////////////////////

// Checks if the shader compilation was successful - Vertex shaders
void sfglShaderRenderer::shaderCompileSuccessCheckVertex()
{
	int success;
	char infoLog[512];

	for (int i = 0; i < 2; i++)
	{
		glGetShaderiv(vertexShader[i], GL_COMPILE_STATUS, &success);

		// IF not successfull, print out compilation fail and the info log
		if (!success)
		{
			glGetShaderInfoLog(vertexShader[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\N" << infoLog << std::endl;
		}
	}
}

	

// Checks if the shader compilation was successful - Fragment shaders
void sfglShaderRenderer::shaderCompileSuccessCheckFragment()
{
	int success;
	char infoLog[512];

	for (int i = 0; i < 2; i++)
	{
		glGetShaderiv(fragmentShader[i], GL_COMPILE_STATUS, &success);

		// IF not successfull, print out compilation fail and the info log
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\N" << infoLog << std::endl;
		}
	}
	}
	

// Checks if the shader linking was successful
void sfglShaderRenderer::shaderLinkingSuccessCheck(int shaderProgram[])
{
	int success;
	char infoLog[512];

	for (int i = 0; i < 2; i++)
	{
		glGetProgramiv(shaderProgram[i], GL_LINK_STATUS, &success);

		// IF not successfull, print out compilation fail and the info log
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram[i], 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::LINKING::SHADER_LINKING_FAILED\N" << infoLog << std::endl;
		}
	}

	
}