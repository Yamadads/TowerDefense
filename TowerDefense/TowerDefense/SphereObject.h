#pragma once

#include "Shader.h"
#include "SceneObject.h"
#include "Sphere.h"
#include "LightManager.h"

class SphereObject : public SceneObject
{
private:
	Sphere *sphere = nullptr;	
	LightManager *lightManager;
	unsigned long long lightId;
	GLuint VBO, VAO, EBO;
	glm::vec4 uColor;

	void setupVAO();
	void configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
public:
	void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	SphereObject(Sphere *newSphere, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec4 color);
	~SphereObject();

	glm::vec4 getColor();
	void setColor(glm::vec4 color);

	Sphere *getSphere();
	void setSphere(Sphere *newSphere);
};

