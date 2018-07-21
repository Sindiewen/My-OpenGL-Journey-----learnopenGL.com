#include "headers\sfglShaderRenderer.h"

// Default constructor
sfglShaderRenderer::sfglShaderRenderer()
{
	// default constructor
	// Sets the source code for the shaders
	
	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
			"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}";

	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}";
		
}

// Start the shader renderer
// Compiles the shader renderer
void sfglShaderRenderer::compileShaders()
{
	// Compiles the Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);			// Tells shader program to create a vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);	// Attaching the shader source to the vertex shader
	glCompileShader(vertexShader);								// Compiles the attached vertex shader
	shaderCompileSuccessCheckVertex();							// Checks to see if the vertex shader compiles successfully

	// Compiles the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);			// Tells shader program to create fragment shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);	// Attach the fragment shader source to the fragment shader
	glCompileShader(fragmentShader);								// Compiles the fragment shader
	shaderCompileSuccessCheckFragment();							// CHecks to see if the fragment shader compiled successfully

	
}

void sfglShaderRenderer::createShaderProgram(int &shaderProgram)
{
	// Attach shaders to the shader program
	glAttachShader(shaderProgram, vertexShader);		// Attaches vertex shader to the shader program
	glAttachShader(shaderProgram, fragmentShader);		// Attaches fragment shader to the shader program
	glLinkProgram(shaderProgram);						// Links the shaders to the program
	shaderLinkingSuccessCheck(shaderProgram);			// Checks to see if the shader linking was successful

	// Deletes old shader object as the program was run
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


//////////////////////////
// Shader Error Checking
//////////////////////////

// Checks if the shader compilation was successful
void sfglShaderRenderer::shaderCompileSuccessCheckVertex()
{
	int success;
	char infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	// IF not successfull, print out compilation fail and the info log
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\N" << infoLog << std::endl;
	}
}

void sfglShaderRenderer::shaderCompileSuccessCheckFragment()
{
	int success;
	char infoLog[512];

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	// IF not successfull, print out compilation fail and the info log
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\N" << infoLog << std::endl;
	}
}

void sfglShaderRenderer::shaderLinkingSuccessCheck(int &shaderProgram)
{
	int success;
	char infoLog[512];

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	// IF not successfull, print out compilation fail and the info log
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING::SHADER_LINKING_FAILED\N" << infoLog << std::endl;
	}
}