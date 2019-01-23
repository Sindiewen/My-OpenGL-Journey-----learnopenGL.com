#pragma once // For Visual Studio
#ifndef SFGLMAIN_H
#define SFGLMAIN_H

//Preprocesor directives
#include "sfglRenderer.h"

// main class for GLFW OpenGL Renderer
class sfglMain
{
public:
	void StartRenderer();	// Starts the OpenGL Renderer
	void TerminateRenderer(); // Ends the OpenGL Renderer

	// class constructor
	sfglMain();
	sfglMain(int resW, int resH);
	sfglMain(int resW, int resH, const char windowName[], bool InitMacOs);
	sfglMain(int resW, int resH, const char windowName[], int glfwVersionMajor, int glfwVersionMinor, bool InitMacOs);

	
private:

	// Private variables
	GLFWwindow* window;		// Initialize window object pointer

	// Object to the GLRenderer
	sfglRenderer glRenderer;


	// glfw Window Init functions
	void _glfwInitWindow(int glfwVersionMajor, int glfwVerionMinor, bool InitMacOs);
	void _glfwCreateWindow(int resW, int resH, const char windowName[]);
	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);



	/*
	// OpenGL Render Functions
	void glUpdate();

	// GLFW Input Checks
	void processInput();
	*/

};


#endif
