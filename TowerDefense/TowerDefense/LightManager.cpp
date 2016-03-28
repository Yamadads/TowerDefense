#include "LightManager.h"

LightManager& LightManager::getLightManager(){
	static LightManager *lightManager = NULL;

	if (lightManager == NULL)
	{		
		lightManager = new LightManager();
	}

	return *lightManager;
}
void LightManager::destroyLightManager(){
	LightManager *lightManager = &getLightManager();
	delete lightManager;
}

LightManager::LightManager(){
	pointLights = new std::vector<PointLight*>();
	
	pointLights->push_back(new PointLight(glm::vec3(1.0f, 1.0f, 1.0f)));
	pointLights->push_back(new PointLight(glm::vec3(1.0f, 1.0f, -1.0f)));
	pointLights->push_back(new PointLight(glm::vec3(-1.0f, 1.0f, 1.0f)));
	pointLights->push_back(new PointLight(glm::vec3(-1.0f, 1.0f, -1.0f)));
	
	dirLight.direction = glm::vec3(-0.2f, -1.0f, 0.0f);
	dirLight.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	dirLight.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
	dirLight.specular = glm::vec3(0.5f, 0.5f, 0.5f);
	
}

LightManager::~LightManager(){
	for (int i = 0; i < pointLights->size(); i++){
		delete (*pointLights)[i];
	}
	delete pointLights;
}

int LightManager::getPointLightsNumber(){
	return pointLights->size();
}

std::vector<PointLight*> *LightManager::getPointLights(){
	return pointLights;
}

DirLight LightManager::getDirLight(){
	return dirLight;
}

void LightManager::setDirLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular){
	dirLight.ambient = ambient;
	dirLight.diffuse = diffuse;
	dirLight.direction = direction;
	dirLight.specular = specular;
}