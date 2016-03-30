#pragma once
#include <iostream>
#include <map>
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
	//max 20 point lights

	unsigned long long id = 0;
	std::map<unsigned long long, PointLight*> *pointLights; 
	DirLight dirLight;

	LightManager();
	~LightManager();

	unsigned long long getNewID();
public:
	DirLight getDirLight();
	void setDirLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse,	glm::vec3 specular);
	int getPointLightsNumber();
	std::map<unsigned long long, PointLight*> *getPointLights();
	static LightManager& getLightManager();
	static void destroyLightManager();
};

