#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "PointLight.h"
#include <GLFW/glfw3.h>

struct DirLight {
	glm::vec3 direction;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};

class LightManager
{
private:

	std::vector<PointLight*> *pointLights;
	DirLight dirLight;
	LightManager();
	~LightManager();

public:
	DirLight getDirLight();
	void setDirLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse,	glm::vec3 specular);
	int getPointLightsNumber();
	std::vector<PointLight*> *getPointLights();
	static LightManager& getLightManager();
	static void destroyLightManager();
};

