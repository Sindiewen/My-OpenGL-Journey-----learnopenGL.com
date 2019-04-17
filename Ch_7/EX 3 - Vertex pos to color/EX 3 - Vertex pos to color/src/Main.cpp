// Preprocessor directives

//Starfold Engine start
#include "headers/sfglMain.h"

// Main fn - Where the fun begins
int main()
{
	sfglMain glWindow(1024, 768, "Hello Triangle with Classes", false);	// Creates the gl Window object


	glWindow.StartRenderer();	// Initiates the renderer dn gl project

	// When the window is set to close, only then will the start renderer funciton will be left and then
	// this will be terminated.
	glWindow.TerminateRenderer();


	return 0;
}


