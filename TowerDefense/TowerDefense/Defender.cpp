#include "Defender.h"

Defender::Defender(std::string id, ModelObject *defenderObject, std::map<std::string, SceneObject *> *sceneObjects,
	std::map<std::string, Enemy *> *enemies, SphereObject *sphereObject){
	objects = sceneObjects;
	this->enemies = enemies;
	bullet = sphereObject;
	object = defenderObject;
	objectID = id;
	bulletID = id + "b";
	(*objects)[objectID] = object;
	(*objects)[bulletID] = bullet;
	ready = false;
}

Defender::~Defender(){
	delete object;
	delete bullet;
	objects->erase(objectID);
	objects->erase(bulletID);
}

bool Defender::move(float speed){
	return false;
}

std::string Defender::getID(){
	return objectID;
}

ModelObject *Defender::getObject(){
	return object;
}

SphereObject *Defender::getBullet(){
	return bullet;
}

void Defender::shot(int hitScore, double deltaTime){
	if (!ready){
		return;
	}
	float speed = 0.1;
	if (tempEnemy != NULL){
		bullet->setMovementDirection(tempEnemy->getPosition()-bullet->getPosition());
		bullet->setVelocity(glm::vec3(bullet->getMovementDirection().x*speed*deltaTime,
			  						bullet->getMovementDirection().y*speed*deltaTime,
									bullet->getMovementDirection().z*speed*deltaTime));
		bullet->setPosition(bullet->getPosition() + bullet->getVelocity());		
		if ((glm::distance(tempEnemy->getPosition(), bullet->getPosition()))<1){			
			tempEnemy->hit(hitScore);
			tempEnemy = NULL;
		}
	}
	else{
		bullet->setPosition(glm::vec3(object->getPosition().x, object->getPosition().y+3, object->getPosition().z));
		if (enemies->size()!=0){
			for (map<string, Enemy *>::iterator iterator = enemies->begin(); iterator != enemies->end(); iterator++)
			{
				if (glm::distance(iterator->second->getPosition(), object->getPosition()) < 20){
					tempEnemy = iterator->second;
					break;
				}
			}
		}
	}
}

void Defender::activate(){	
	ready = true;
}