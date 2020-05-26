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


// ----------------------------------------------------
// render shapes

// Setup Rendering
void sfglRenderer::setupTwoSeparateTrianglesToRender()
{
	// NOTE:
	/*
	It seems that to render the 2 separate triangles with their own VAO and VBO, when you setup
	the VAO and here you NEED to make sure that they're all grouped up properly.
	VAO and VBO 1 stuff first, then 2nd afterwards.
	*/
	// Triangle 1
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triOneVerts), triOneVerts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Triangle 2
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triTwoVerts), triTwoVerts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind vertex array
	glBindVertexArray(0);

}


void sfglRenderer::renderTriangle()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBindVertexArray(0);
}

// ----------------------------------------------------
// GLFW - Renderer Update
////////////////////////
void sfglRenderer::glUpdate()
{
	// Initialization(done once unless object changes)


	// Define graphics buffer
	// There are 2 VAO/VBO's, no need to pass reference, just specify the amount of each and pass variable
	glGenVertexArrays(2, VAOs);			// Generates vertex array
	glGenBuffers(2, VBOs);				// Generates the buffer
	
	// ---------------------------------------------------
	setupTwoSeparateTrianglesToRender();
	 

	while (!glfwWindowShouldClose(window))
	{
		// Check and process input
		processInput();



		// Renders to the viewport
		glClearColor(0.3f, 0.1f, 0.6f, 1.0f);
		// Clears the buffer readying for the next frame
		glClear(GL_COLOR_BUFFER_BIT);




		// Draw the shapes on screen
		// --------------------------------------------
		// Pattern: Bind first triangle vertex array, then render triangle, then render 2nd vertex array, and then render triangle

		// Bind first triangle
		// First triangle is orange
		glUseProgram(shaderProgram[0]);
		glBindVertexArray(VAOs[0]);
		// Draw triangle
		renderTriangle();

		// bind 2nd triangle
		// 2nd triangle is yellow
		glUseProgram(shaderProgram[1]);
		glBindVertexArray(VAOs[1]);
		renderTriangle();






		// Check for any call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
}




void sfglRenderer::processInput()
{
	// Checks to see if the escape key has been pressed. If presed, set property to true to initiate window close
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
