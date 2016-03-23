#include <GLFW/glfw3.h>
/*
GLfloat wallVertices[] = {
	// Positions          // Normals         // Texture Coords
	8.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 5.0f, 0.0f,
	-8.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	-8.0f, 0.0f, -2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 5.0f,
	8.0f, 0.0f, -2.0f, 0.0f, 1.0f, 0.0f, 5.0f, 5.0f
};

GLuint wallIndices[] = {  // Note that we start from 0!
	0, 1, 2, // First Triangle
	0, 2, 3  // Second Triangle
};
*/
string wallTextures = { "Resources/grass.jpg" };

GLfloat wallVertices[] = {
	// Positions          // Colors           // Texture Coords
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
};
GLuint wallIndices[] = {  // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3  // Second Triangle
};