#include "Enemy.h"

Enemy::Enemy(std::string id, ModelObject *enemyObject, glm::vec3 target, std::map<std::string, SceneObject *> *sceneObjects){
	objects = sceneObjects;
	lifePoints = 100;
	object = enemyObject;
	this->target = target;
	(*objects)[id] = object;
	this->id = id;
	glm::vec3 direction = glm::normalize(target - object->getPosition());
	object->setMovementDirection(glm::vec3(direction.x, 0, direction.z));	
}

Enemy::~Enemy(){
	delete object;
	objects->erase(id);
}

int Enemy::getLifePoints(){
	return lifePoints;
}

bool Enemy::hit(int force){
	lifePoints -= force;
	if (lifePoints <= 0){
		lifePoints = 0;
		return true;
	}
	return false;
}

bool Enemy::move(float speed){
	//object->setPosition(object->getVelocity());
	//glm::vec3 oldPosition = object->getPosition();	
	object->setVelocity(glm::vec3(object->getMovementDirection().x*speed, 
								  object->getMovementDirection().y*speed,
								  object->getMovementDirection().z*speed));

	object->setPosition(object->getPosition() + object->getVelocity());		
	
	if ((glm::distance(target, object->getPosition()))<3){
		return true;
	}
	return false;
	//glm::vec3 movementDirection = normalize(object->getPosition()-oldPosition);
	//object->setMovementDirection(movementDirection);
}

std::string Enemy::getID(){
	return id;
}