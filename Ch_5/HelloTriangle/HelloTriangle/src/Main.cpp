// Preprocessor directives
#include <iostream>

// OpenGL Directives
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// Function Prototypes
// Window Initialization Functions
void glfwInitWindow();		// Initializes the OpenGL Window
GLFWwindow* glfwCreateWindow();	// Creates the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);	// Prototype to update window with new size

// glfw Update Fn
void glUpdate(GLFWwindow* window);	// The GL Update Function

// Input Functions
void processInput(GLFWwindow* window);	// Processess input

// Render Functions



// Main fn
int main()
{
	// Initializes OpenGL Window
	glfwInitWindow();

	// Creates the window
	GLFWwindow* window = glfwCreateWindow();

	// if null, terminate program;
	if (window == NULL)
	{
		return -1;
	}

	// Initializes GLAD - manges funciton pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Creates the viewport - sets location of the lower left corner of window, then resolution
	glViewport(0, 0, 1280, 720);

	// If the user rezises the window, callback to the window and update the window size
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	//////////////////////////////////////////////////////////////////////////////////////////
	// Starts running the glUpdate Function
	glUpdate(window);

	
	// When render loop exited, clean up any and all gl resources.
	glfwTerminate();
	return 0;
}

void glUpdate(GLFWwindow* window)
{
	// glUpdate Variables
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // X Axis
		0.5f, -0.5f, 0.0f,	// Y Axis
		0.0f, 0.5f, 0.0f,	// Z Axis
	};

	unsigned int VBO;	// initializes the currently bound buffer

	// Starts the render loop
	while (!glfwWindowShouldClose(window))
	{
		// Checks for any input updates
		processInput(window);

		// Renders to the viewport
		glClearColor(0.5, 0.1, 0.2, 1.0);	// Sets clear color


		glGenBuffers(1, &VBO);				// Generate buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);	// Binds the buffer
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);	// Copies previously defined vertex data into the buffer memory








		glClear(GL_COLOR_BUFFER_BIT);		// Clear the window for next frame


		// Checks call events and swap the buffers
		glfwSwapBuffers(window);	// Swaps color buffer to show output to the display
		glfwPollEvents();			// Checks to see if any input has been triggered
	}
}






////////////////////////
// GLFW Init Functions
////////////////////////
// Initializes the OpenGL Window.
void glfwInitWindow()
{
	// Initialize the GLFW window
	glfwInit();

	// Set version of Open GL to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tells OpenGL to use the core profile without backwards compatible stuff. Reduces bloat?
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// For MacOS, Add line to initialization to work.
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
}

// Creates the glfw Window
GLFWwindow* glfwCreateWindow()
{
	// Window Creation - Resolution and Window Name
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Hello Window - Learn OpenGL", NULL, NULL);

	// Checks if the window was initializes successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return NULL;
	}

	// makes the window main context on current thread
	glfwMakeContextCurrent(window);

	// Returns the successfully created window object
	return window;
}

// Updates the window size when resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


///////////////////////////////////////
// GL Update Functions
///////////////////////////////////////


// Processess any input
void processInput(GLFWwindow* window)
{
	// Checks to see if the escape key has been pressed. If so, set property to true to initiate window close
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
