#include "headers\sfglMain.h"

// Function Prototypes (for no class functions)
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


/////////////////////
// Class Constructors
//////////////////////
// Default Constructor	-- Sets default gl window values
sfglMain::sfglMain() 
{
	// Init GLFW window with default values
	_glfwInitWindow(3, 3, false);

	// Create window
	_glfwCreateWindow(800, 600, "Default Window Name");

	// Initialize GLAD - Manages function pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	// Create the Viewport
	glViewport(0, 0, 800, 600);

	// If user resizes window, callback to the window and update the window size
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

}

sfglMain::sfglMain(int resW, int resH)
{
	// Init GLFW window with default values
	_glfwInitWindow(3, 3, false);

	// Create window
	_glfwCreateWindow(resW, resH, "Default Window Name");

	// Initialize GLAD - Manages function pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	// Create the Viewport
	glViewport(0, 0, resW, resH);

	// If user resizes window, callback to the window and update the window size
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

sfglMain::sfglMain(int resW, int resH, const char windowName[], bool InitMacOs)
{
	// Init GLFW window with default values
	_glfwInitWindow(3, 3, InitMacOs);

	// Create window
	_glfwCreateWindow(resW, resH, windowName);

	// Initialize GLAD - Manages function pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

// Create the Viewport
glViewport(0, 0, resW, resH);

// If user resizes window, callback to the window and update the window size
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

sfglMain::sfglMain(int resW, int resH, const char windowName[], int glfwVersionMajor, int glfwVersionMinor, bool InitMacOs)
{
	// Init GLFW window with default values
	_glfwInitWindow(glfwVersionMajor, glfwVersionMinor, InitMacOs);

	// Create window
	_glfwCreateWindow(resW, resH, windowName);

	// Initialize GLAD - Manages function pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	// Create the Viewport
	glViewport(0, 0, resW, resH);

	// If user resizes window, callback to the window and update the window size
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


////////////////////////
// GLFW Init Functions
////////////////////////

// glfw Window Init
void sfglMain::_glfwInitWindow(int glfwVersionMajor, int glfwVerionMinor, bool InitMacOs = false)
{
	// Initialize the GLFW window
	glfwInit();

	// Set version of Open GL to use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfwVersionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfwVerionMinor);

	// Tells OpenGL to use the core profile without backwards compatible stuff. Reduces bloat?
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// For MacOS specifically
	if (InitMacOs)
	{
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	}
}

// glfw Window Creation
void sfglMain::_glfwCreateWindow(int resW, int resH, const char windowName[])
{
	// Create window with passed in resolution and name
	window = glfwCreateWindow(resW, resH, windowName, NULL, NULL);

	// Check if window was initialized successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	// Makes window main context on current thread
	glfwMakeContextCurrent(window);

}

// Updates the size of the GL Window callback function - Non class function
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}




////////////////////////
// GLFW - Renderer Functions
////////////////////////

void sfglMain::StartRenderer()
{
	// TODO: Start shader stuff here

	// Start the update loop in the renderer class
	//glUpdate();
	glRenderer.setWindow(window);
	glRenderer.initiateRenderer();
}

// Terminates the OpenGL Renderer
void sfglMain::TerminateRenderer()
{
	glfwTerminate();
}



/*
////////////////////////
// GLFW - Renderer Update
////////////////////////

// The updtate function
void sfglMain::glUpdate()
{
	while (!glfwWindowShouldClose(window))
	{
		// Check and process input
		processInput();

		// Renders to the viewport
		glClearColor(0.6f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Check for any call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}


// Process input
void sfglMain::processInput()
{
	// Checks to see if the escape key has been pressed. If presed, set property to true to initiate window close
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

////////////////////////
// Window getters and setters
////////////////////////

GLFWwindow* sfglMain::_getWindow()
{
	return window;
}
*/
