#include "headers\sfglShaderRenderer.h"

// ------------------------------------
// Default constructor
sfglShaderRenderer::sfglShaderRenderer()
{
	// default constructor
	// Sets the source code for the shaders
	
	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"out vec4 vertexColor;\n"	// Sets vertex color variable variable going out
		"void main()\n"
		"{\n"
			// Setting a vector3 into the vector4's constructor. Needs 1 more parameter though as it is a vector4
			"gl_Position = vec4(aPos, 1.0);\n"

			// Setting the output color for the shader
			//"vertexColor = vec4(0.5, 0.0, 0.0, 1.0)\n;"
		"}";

	/* Fragment shader - Getting vertex color from vertex shader source
	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"		// Defines the output color to the vertex
			
		"in vec4 vertexColor;\n"	// Takes in the vertexColor variable from the vertexShader - has same variable name

		"void main()\n"
		"{\n"
		"	FragColor = vertexColor;\n"
		"}";
		*/

	fragmentShaderSource = "#version 330 core\n"
		"uniform vec4 outColor;\n"	// Global: set in the openGL code
		"void main()\n"
		"{\n"
		"	FragColor = vertexColor;\n"
		"}";
		
}

// ----------------------------------------------
// Start the shader renderer
// Assigns the shader source code
void sfglShaderRenderer::assignShaderSource(const char* vertexSource, const char* fragmentSource)
{
	vertexShaderSource = vertexSource;
	fragmentShaderSource = fragmentSource;
}

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

// Creates the shader program
void sfglShaderRenderer::createShaderProgram(int &shaderProgram)
{
	// Attach shaders to the shader program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);		// Attaches vertex shader to the shader program
	glAttachShader(shaderProgram, fragmentShader);		// Attaches fragment shader to the shader program
	glLinkProgram(shaderProgram);						// Links the shaders to the program
	shaderLinkingSuccessCheck(shaderProgram);			// Checks to see if the shader linking was successful

	// Deletes old shader object as the program was run
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


// --------------------------------------
// Shader Error Checking
//////////////////////////

// Checks if the shader compilation was successful - Vertex shaders
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

// Checks if the shader compilation was successful - Fragment shaders
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

// Checks if the shader linking was successful
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