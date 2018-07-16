// Preprocessor directives
#include <iostream>
#include <cstdlib>
#include <ctime>

// OpenGL Directives
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Function Prototypes

// Window Initialization Functions
void glfwInitWindow();		// Initializes the OpenGL Window
GLFWwindow* glfwCreateWindow();	// Creates the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);	// Prototype to update window with new size


// Input Functions
void processInput(GLFWwindow* window, bool& spacePressed);	// Processess input

// Render Functions
void setRandomRGBAValues(double& r, double& g, double& b, double& a);
void setClearColor(double r, double g, double b, double a);


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


	// Initialize random number generator
	srand(static_cast<double>(time(0)));

	// Variables
	bool spacePressed = false;	// If space has been pressed
	double r = 0.2, g = 0.3, b = 0.3, a = 1.0;	// Stores rgba values of the clear color
	


	// Starts the render loop
	while (!glfwWindowShouldClose(window))
	{
		// Checks for any input updates
		processInput(window, spacePressed);

		// Renders to the viewport
		// If space has been pressed, set random rgba values
		if (spacePressed)
		{
			spacePressed = false;
			setRandomRGBAValues(r, g, b, a);
		}
		// Sets the clear color
		setClearColor(r, g, b, a);

		// Checks call events and swap the buffers
		glfwSwapBuffers(window);	// Swaps color buffer to show output to the display
		glfwPollEvents();			// Checks to see if any input has been triggered
	}

	
	// When render loop exited, clean up any and all gl resources.
	glfwTerminate();
	return 0;


	return 0;
}

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

// Processess any input
void processInput(GLFWwindow* window, bool& spacePressed)
{
	// Checks to see if the escape key has been pressed. If so, set property to true to initiate window close
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	// If user pressed space, set to true
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS || glfwGetKey(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		spacePressed = true;
	}
}

// Sets random rgba values
void setRandomRGBAValues(double& r, double& g, double& b, double& a)
{
	double randR = rand();
	double randG = rand();
	double randB = rand();
	double randA = rand();

	// Sets random numbers
	r = randR / RAND_MAX;
	g = randG / RAND_MAX;
	b = randB / RAND_MAX;
	a = randA / RAND_MAX;

	std::cout << "r = " << r << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a = " << a << std::endl;
}

// Sets the clear color
void setClearColor(double r, double g, double b, double a)
{
	glClearColor(r, g, b, a);	// sets clear color to the display
	glClear(GL_COLOR_BUFFER_BIT);			// Clears the screan
}