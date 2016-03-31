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
	lightPoints = new std::map<unsigned long long, PointLight*>();
	
	dirLight.direction = glm::vec3(-0.2f, -1.0f, 0.0f);
	dirLight.ambient = glm::vec3(0.1f, 0.1f, 0.1f);
	dirLight.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
	dirLight.specular = glm::vec3(0.5f, 0.5f, 0.5f);
	
}

LightManager::~LightManager(){
	for (std::map<unsigned long long, PointLight*>::iterator iterator = lightPoints->begin(); iterator != lightPoints->end(); iterator++)
	{
		delete (*iterator).second;
	}
	delete lightPoints;
}

int LightManager::getLightPointsNumber(){
	return lightPoints->size();
}

std::map<unsigned long long, PointLight*> *LightManager::getLightPoints(){
	return lightPoints;
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

unsigned long long LightManager::getNewID(){	
	return id++;	
}

unsigned long long LightManager::addLightPoint(glm::vec3 position){
	unsigned long long newLigntID = getNewID();
	(*lightPoints)[newLigntID] = new PointLight(position);
	return newLigntID;
}