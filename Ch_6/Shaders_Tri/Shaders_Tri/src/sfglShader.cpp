#include "headers\sfglShader.h"

// ------------------------------------
// Default constructor
sfglShader::sfglShader()
{
	// default constructor
	// Sets the source code for the shaders
	// Depricated - Used for manually assigning shader source here

	/*
	/// Rainbow triangle
	vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 vertexColor;\n"	// Sets vertex color variable variable going out to fragment
		"void main()\n"
		"{\n"
			// Setting a vector3 into the vector4's constructor. Needs 1 more parameter though as it is a vector4
			"gl_Position = vec4(aPos, 1.0);\n"
		
			// Setting vertexColor to aColor
			"vertexColor = aColor;\n"

			// Setting the output color for the shader
			//"vertexColor = vec4(0.5, 0.0, 0.0, 1.0)\n;"
		"}";

	//Fragment shader - Getting vertex color from vertex shader source
	fragmentShaderSource = "#version 330 core\n"
		"out vec3 FragColor;\n"		// Defines the output color to the vertex
			
		"in vec3 vertexColor;\n"	// Takes in the vertexColor variable from the vertexShader - has same variable name

		"void main()\n"
		"{\n"
		"	FragColor = vertexColor;\n"	// Recives the passed in vertexColor
		"}";
		

	// Fragment SHader using Uniforms
	/*
	fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"	// Global: set in the openGL code
		"void main()\n"
		"{\n"
		"	FragColor = ourColor;\n"
		"}";
		*/
	
	
		
}

// Passing in shader source files
sfglShader::sfglShader(const char* vertexPath, const char* fragPath)
{
	
	// 1: string and fstream variables
	std::string vertexSource;
	std::string fragmentSource;
	std::ifstream finVertex;
	std::ifstream finFrag;

	// Ensures the fstream objects can throw exceptions
	finVertex.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	finFrag.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Excepion handling: Trys reading from file, catch fail
	try 
	{
		// Opens files
		finVertex.open(vertexPath);
		finFrag.open(fragPath);
		std::stringstream vShaderStream, fShaderStream;

		// Reads file buffers into streams
		// TODO: Learn about stringstream
		vShaderStream << finVertex.rdbuf();
		fShaderStream << finFrag.rdbuf();

		// Closes file handlers
		finVertex.close();
		finFrag.close();

		// Converts stream into string
		vertexSource = vShaderStream.str();
		fragmentSource = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	const char* vertexShaderSource = vertexSource.c_str();
	const char* fragmentShaderSource = fragmentSource.c_str();

	// Compiles and creates the shaders
	compileShaders(vertexShaderSource, fragmentShaderSource);
	createShaderProgram();
}

// ------------------------------------------------
// Defines and sets the Uniform

void sfglShader::definesShaderUniform()
{
	// ------------------------------------------------------
	// sin color change 

	float timeValue = glfwGetTime();	// Gets the current running time of the program (seconds.milliseconds)
	float greenValue = sin(timeValue + 2.0f) + 0.5f;	// Sets the green value between 1 and -1 
	// TODO: Understand how sin works
	// Seems to create a sin wave when printing out the numbers to the console.
	int vertexColorLocation = glGetUniformLocation(ShaderProgram, "ourColor");	// Uses shader program, and assigns the uniform to ourColor
	glUniform4f(vertexColorLocation ,0.0f, greenValue, 0.0f, 1.0f);
	//std::cout << "Current Time Value: " << timeValue << std::endl;
	//std::cout << "Current Green Value: " << greenValue << std::endl;
}

// ----------------------------------------------
// Start the shader renderer
// Assigns the shader source code
void sfglShader::assignShaderSource(const char* vertexPath, const char* fragPath)//(const std::string filePath)//(const std::string vertexPath, const std::string fragPath)//(const char* vertexPath, const char* fragPath)
{
	// HUGE NOTE: When I try to load a shader file, it refuses to load the file overall. From what I've researched, it's regarding an illegal
	// character in the file so idk. im gonna gonna continue this and load my shaders through the constructor

	// 1: string and fstream variables
	std::string vertexSource;
	std::string fragmentSource;
	std::ifstream finVertex;
	std::ifstream finFrag;
	
	// Ensures the fstream objects can throw exceptions
	finVertex.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	finFrag.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Excepion handling: Trys reading from file, catch fail
	try
	{
		// Opens files
		finVertex.open(vertexPath);
		finFrag.open(fragPath);
		std::stringstream vShaderStream, fShaderStream;

		// Reads file buffers into streams
		// TODO: Learn about stringstream
		vShaderStream << finVertex.rdbuf();
		fShaderStream << finFrag.rdbuf();

		// Closes file handlers
		finVertex.close();
		finFrag.close();

		// Converts stream into string
		vertexSource = vShaderStream.str();
		fragmentSource = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	// Assigns the shader source code
	// oh god... kill me... this is like tthe worst error i've ever had to deal with in my 5 yaers of programming
	// I want to pass in the shader source code. OH SURE I'LL MAKE A CONST CHAR* AND ASSIGN BALUES TO IT LATER YEAH NO PROB
	// OH WAIT 6 MONMTHS LATER I REALIZES HEY THAT DOESNT WORK AND I DIDNT REALIZE IT UNTILL LITTERALLY EARLIER TODAY
	// gah that's why it wasnt working I should work on a farm
	const char* vertexShaderSource = vertexSource.c_str();
	const char* fragmentShaderSource = fragmentSource.c_str();

	// Compiles the shaders
	compileShaders(vertexShaderSource, fragmentShaderSource);
	createShaderProgram();
}

// Compiles the shader renderer
void sfglShader::compileShaders(const char* vertexShaderSource, const char* fragmentShaderSource)
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
void sfglShader::createShaderProgram()
{
	// Attach shaders to the shader program
	ShaderProgram = glCreateProgram();
	glAttachShader(ShaderProgram, vertexShader);		// Attaches vertex shader to the shader program
	glAttachShader(ShaderProgram, fragmentShader);		// Attaches fragment shader to the shader program
	glLinkProgram(ShaderProgram);						// Links the shaders to the program
	shaderLinkingSuccessCheck();			// Checks to see if the shader linking was successful

	// Deletes old shader object as the program was run
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// Uses the shader program 
void sfglShader::UseShader()
{
	glUseProgram(ShaderProgram);
}



// --------------------------------------
// Shader Error Checking
//////////////////////////

// Checks if the shader compilation was successful - Vertex shaders
void sfglShader::shaderCompileSuccessCheckVertex()
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
void sfglShader::shaderCompileSuccessCheckFragment()
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
void sfglShader::shaderLinkingSuccessCheck()
{
	int success;
	char infoLog[512];

	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);

	// IF not successfull, print out compilation fail and the info log
	if (!success)
	{
		glGetProgramInfoLog(ShaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING::SHADER_LINKING_FAILED\N" << infoLog << std::endl;
	}
}




// -------------------------------------
// Shader Uniform setters 
void sfglShader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ShaderProgram, name.c_str()), (int)value);
}

void sfglShader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ShaderProgram, name.c_str()), value);
}

void sfglShader::setFloat(const std::string &name, int value) const
{
	glUniform1f(glGetUniformLocation(ShaderProgram, name.c_str()), value);
}


