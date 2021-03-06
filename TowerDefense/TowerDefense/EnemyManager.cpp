#include "EnemyManager.h"
#include "ModelObject.h"
#include "Player.h"
#include <cmath>
#include <glm/gtx/vector_angle.hpp>

EnemyManager& EnemyManager::getEnemyManager(){
	static EnemyManager *enemyManager = NULL;
	if (enemyManager == NULL)
	{
		enemyManager = new EnemyManager();
	}
	return *enemyManager;
}

void EnemyManager::destroyEnemyManager()
{
	EnemyManager *enemyManager = &getEnemyManager();
	delete enemyManager;
}

std::map<std::string, Enemy*>* EnemyManager::getEnemies(){
	return enemies;
}

EnemyManager::EnemyManager(){
	playerDamage = 20;
	enemies = new std::map<std::string, Enemy*>();		
}

EnemyManager::~EnemyManager(){
	for (map<string, Enemy *>::iterator iterator = enemies->begin(); iterator != enemies->end(); iterator++)
	{
		delete (*iterator).second;
	}
	delete enemies;
}

void EnemyManager::addEnemy(){
	double radius = 55;
	double angle = rand()*3.1415 * 2;
	double x = cos(angle)*radius;
	double y = 4;
	double z = sin(angle)*radius;
	 
	ModelObject *object = new ModelObject(scene->getModel("raptor"), glm::vec3(x, y, z), scene->getShaderPath("VSlight"), scene->getShaderPath("FSlight"));

	object->setScale(glm::vec3(0.2f, 0.2f, 0.2f));	

	glm::vec3 targetPosition = (*(scene->getChildren()))["megatron"]->getPosition();		
	glm::vec2 u = glm::vec2(0,-1);
	glm::vec2 v = glm::normalize(glm::vec2(targetPosition.x,targetPosition.z)-glm::vec2(x,z)); 
	double angle2 = -1 * 180 / 3.14 * fmodf(atan2(u.x*v.y - v.x*u.y, u.x*v.x + u.y*v.y), 2 * 3.14);	
	object->setRotation(glm::vec3(270, 0, (GLfloat)angle2));

	string newEnemyID = getNewId();
	Enemy *enemy = new Enemy(newEnemyID, object, targetPosition, scene->getChildren());
	(*enemies)[newEnemyID] = enemy;
}

std::string EnemyManager::getNewId(){
	std::string newID = "enemy";
	newID.append(std::to_string(id));
	id++;
	return newID;
}

void EnemyManager::update(double deltaTime){
	Player *player = &Player::getPlayer();
	float speed = 0.05+player->getPoints()/500;
	vector<string> *toKill = new vector<string>();
	//move enemies
	for (map<string, Enemy *>::iterator iterator = enemies->begin(); iterator != enemies->end(); iterator++)
	{
		//move enemy and react if hit megatron
		if (iterator->second->move(deltaTime, speed)){
			//add to kill list 
			toKill->push_back(iterator->second->getID());				
			Player *player = &Player::getPlayer();
			player->reduceHealth(playerDamage);
		}
		if (iterator->second->getLifePoints() == 0){
			vector<string>::iterator it = std::find(toKill->begin(), toKill->end(), iterator->second->getID());
			if (it == toKill->end()){				
				toKill->push_back(iterator->second->getID());
			}
		}
	}

	//kill 
	for each (std::string kill in (*toKill))
	{		
		player->addPoints(1);

		(*enemies)[kill]->~Enemy();
		(*enemies).erase(kill);
	}
	delete toKill;

	//add new enemy
	double time = glfwGetTime();
	if ((time - lastNewEnemyTime) > delay){
		if (delay>3) delay -= 0.05;
		addEnemy();
		lastNewEnemyTime = glfwGetTime();		
	}
}

double EnemyManager::getDelay(){
	return delay;
}

void EnemyManager::setDelay(double delayTime){
	delay = delayTime;
}

void EnemyManager::setScene(Scene *scene){
	this->scene = scene;
}
Scene *EnemyManager::getScene(){
	return scene;
}

int EnemyManager::getPlayerDamage(){
	return playerDamage;
}

void EnemyManager::setPlayerDamage(int newDamage){
	playerDamage = newDamage;
}

