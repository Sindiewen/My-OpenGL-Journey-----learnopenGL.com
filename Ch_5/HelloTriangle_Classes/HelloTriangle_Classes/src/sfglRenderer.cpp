#include "headers/sfglRenderer.h"


/////////////////////
// Class Constructors
/////////////////////
// Default Constructor 
sfglRenderer::sfglRenderer()
{
	// Defines variable values
	
}


////////////////////////
// GLFW - Initialize renderer
////////////////////////
void sfglRenderer::initiateRenderer()
{
	// TODO: Add shader stuff here
	shader.compileShaders();
	shader.createShaderProgram(shaderProgram);

	// Updates the renderer
	glUpdate();
}


////////////////////////
// Setters and getters
////////////////////////
void sfglRenderer::setWindow(GLFWwindow* newwindow)
{
	window = newwindow;
}




////////////////////////
// GLFW - Renderer Update
////////////////////////
void sfglRenderer::glUpdate()
{
	/*
	//////
	// Compile vertex shader
	//////

	// Stores id into vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);					// We're telling the shader program to create a vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);			// attach shader source
	glCompileShader(vertexShader);		// compile the shader

	// CHecks to see if there were any errors in the compilation process
	shaderCompileSuccessCheckVertex();

	///////
	// Compile fragment shader
	///////

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);	// Creates fragment shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);	// Gets the source of the shader
	glCompileShader(fragmentShader);	// compiles the fragment shader

	// Checks to see if there were errors in fragment shader process
	shaderCompileSuccessCheckFragment();



	//////
	// Creating shader program to allow for them to be linked together
	//////

	shaderProgram = glCreateProgram();	// Creating shader program, returning id reference to the program object

	// Attaching and linking shaders to the program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Checks to see if the shader linking was successful
	shaderLinkingSuccessCheck();

	// Can delete the old shader objects now that the program was created
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	*/



	// Initialization(done once unless object changes)


	// Define graphics buffer
	glGenVertexArrays(1, &VAO);			// Generates vertex array
	glGenBuffers(1, &VBO);				// Generates the buffer
	// 1: bind vertex array object
	glBindVertexArray(VAO);

	// 2: copy vertices array into the buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);	// Binds the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);	// Copies previous defined vertex data into the buffer memory

	// 3: set vertex attribute pointers
	// Linking vertex attributes: pg41 of LeanOpenGL Book
	// Determines how OpenGL should interpret the vertex data
	// 1: location 0 from vertex shader, 2: size of vertex is 3, 3: telling opengl that float is being used,
	// 4: Do not want the data to be normalized (allows anything between -1 - 1),
	// 5:determines the "stride distance" between vertex sets [x,y,z|x,y,z|x,y,z] each pair is 12 bytes (4 bytes per float)
	// so each stride costs 12 bytes
	// 6: Offset where the position data begins in the buffer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	// Can unbind vertex array afterward to ensure no accedental modifications of the VAO.
	// Seems optional as this is a rare case anyway.
	glBindVertexArray(0);

	 
	while (!glfwWindowShouldClose(window))
	{
		// Check and process input
		processInput();



		// Renders to the viewport
		glClearColor(0.3f, 0.1f, 0.4f, 1.0f);
		// Clears the buffer readying for the next frame
		glClear(GL_COLOR_BUFFER_BIT);




		// Draw the triangle
		//4: Draw the object on screen
		glUseProgram(shaderProgram);	// use our shader program when we want to render object
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// Check for any call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}




void sfglRenderer::processInput()
{
	// Checks to see if the escape key has been pressed. If presed, set property to true to initiate window close
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
