#pragma once
#include "ModelObject.h"
#include <map>

class Enemy{
private:
	int lifePoints;
	std::string id;
	glm::vec3 target;

	ModelObject *object;
	std::map<std::string, SceneObject *> *objects;

public:
	Enemy(std::string id, ModelObject *enemyObject, glm::vec3 target, std::map<std::string, SceneObject *> *sceneObjects);
	~Enemy();

	glm::vec3 getPosition();
	bool move(double deltaTime, float speed);
	
	std::string getID();
	
	int getLifePoints();	
	bool hit(int force);
};