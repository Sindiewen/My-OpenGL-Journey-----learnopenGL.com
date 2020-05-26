#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

// Prototypes

// Callback function - when the window size changes, this get's called and is adgusts the size of the viewport
// by the size of the window respectively.
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// Input - Processes any input coming in
void processInput(GLFWwindow *window);

// Entry point
int main()
{
	// Initialize aOpenGL Window, version, and core profile without backwards compatible features
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	// Needed for MacOS


	// Create OpenGL window object at 800x600 resolution
    GLFWwindow* window = glfwCreateWindow(800, 600, "4 - Hello Window", NULL, NULL);

    // If the window object is null, that means the glfw failed to create window.
    // Terminate glfw and return -1
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Tell glfw to make this window the main context on the current thread
    glfwMakeContextCurrent(window);


    // GLAD manages funciton pointers for OpenGL. Need to initialize GLAD before we call any OpenGL function
    // if GLAD fails to initialize, close program
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    
    // Tell open gl the size of the render window, the viewport.
    // first 2 argments: sets location to lower left corner of window
    // Last 2 arguments: the width and height of the rendering window in pixels
    glViewport(0, 0, 800, 600);


    // The render loop
    // Checks if the window has been instructed to close. If true, we exit loop
    while(!glfwWindowShouldClose(window))
    {
        // ----------------------------------------------------------------
        // Input
        processInput(window);

        // ----------------------------------------------------------------
        // Rendering commands here
        
        // Give the opengl window a color
        // glClearColor(0.6f, 0.2f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ----------------------------------------------------------------
        // Check and call events and swap the buffers

        // Swaps color buffer to show the next thing in the buffer onscreen
        glfwSwapBuffers(window);

        // Checks if any events are triggered, updates window states and calls corresponding funcitons
        // (Like callbacks)
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Input - Processes any input coming in
void processInput(GLFWwindow *window)
{
    // If user presses the escape key, close window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    // If the user presses r, g or b, the color of the becomes that color
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        glClearColor(1.0f, 0, 0, 1.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        glClearColor(0, 1.0f, 0, 1.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        glClearColor(0, 0, 1.0f, 1.0f);
    }
    
}

// Callback function - when the window size changes, this get's called and is adgusts the size of the viewport
// by the size of the window respectively.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

