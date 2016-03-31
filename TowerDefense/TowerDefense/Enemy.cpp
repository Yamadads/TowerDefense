#include "Enemy.h"

Enemy::Enemy(std::string id, SceneObject *enemyObject, glm::vec3 target, std::map<std::string, SceneObject *> *sceneObjects){
	objects = sceneObjects;
	lifePoints = 100;
	object = enemyObject;
	this->target = target;
	(*objects)[id] = object;
}

Enemy::~Enemy(){
	delete object;
	objects->erase(id);
}

int Enemy::getLifePoints(){
	return lifePoints;
}

void Enemy::hit(int force){
	lifePoints -= force;
	if (lifePoints <= 0){
		delete this;
	}
}
