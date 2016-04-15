#pragma once

#include <GL/glew.h>
#include <ft2build.h>
#include FT_FREETYPE_H  
#include <string>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <GLFW/glfw3.h>


using namespace std;


struct Character {
	GLuint TextureID;   
	glm::ivec2 Size;    
	glm::ivec2 Bearing;  
	GLuint Advance;    
};



class TextRender
{
private:
	GLuint VAO, VBO;
	Shader *shader;

	map<GLchar, Character> Characters;

	void configShader();
	void configText();

	TextRender();
	~TextRender();

public:
	void renderText(string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	static TextRender& getTextRender();
	static void destroyTextRender();
};

