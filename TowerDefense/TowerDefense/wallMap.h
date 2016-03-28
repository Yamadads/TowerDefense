#include <GLFW/glfw3.h>
#include <string>

std::string wallMapTexture = { "Resources/horizon.jpg" };

GLfloat wallWidth = 20;
GLfloat wallHeight = 2;

GLfloat wallMapVertices[] = {
	// Positions          // Normals         // Texture Coords
	-wallWidth, 0.0f, -wallHeight, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	wallWidth, 0.0f, -wallHeight, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f,
	-wallWidth, 0.0f, wallHeight, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	wallWidth, 0.0f, wallHeight, 0.0f, 1.0f, 0.0f, 2.0f, 1.0f
};

GLuint wallMapIndices[] = {  // Note that we start from 0!
	0, 1, 2, // First Triangle
	1, 2, 3  // Second Triangle
};