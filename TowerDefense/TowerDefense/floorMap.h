#include <GLFW/glfw3.h>
#include <string>

std::string floorMapTexture = { "Resources/grass.jpg" };

GLfloat floorSize = 20;

GLfloat floorMapVertices[] = {
	// Positions          // Normals         // Texture Coords
	-floorSize, 0.0f, -floorSize, 0.0f, 1.0f, 0.0f, 5.0f, 0.0f,
	floorSize, 0.0f, -floorSize, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	-floorSize, 0.0f, floorSize, 0.0f, 1.0f, 0.0f, 0.0f, 5.0f,
	floorSize, 0.0f, floorSize, 0.0f, 1.0f, 0.0f, 5.0f, 5.0f
};

GLuint floorMapIndices[] = {
	0, 1, 2, // First Triangle
	1, 2, 3  // Second Triangle
};

