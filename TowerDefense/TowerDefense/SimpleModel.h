#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include "Shader.h"
#include <string>

using namespace std;
/*
each model should have his own shader with specific number of textures
*/
class SimpleModel
{
private:
	GLuint VBO, VAO, EBO;
	GLuint textureHolder;

public:
	SimpleModel(GLfloat *vertices, GLuint verticesSize, GLuint *indices, GLuint indicesSize, string texturePath);
	void draw(Shader *shader);

private:
	void setupVAO(GLfloat vertices[], GLuint verticesSize, GLuint indices[], GLuint indicesSize);
	void loadTexture(const char *filename, GLuint &texture);
};




