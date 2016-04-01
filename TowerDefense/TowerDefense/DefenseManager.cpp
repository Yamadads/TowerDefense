#include "DefenseManager.h"
#include "ModelObject.h"
#include "Player.h"
#include <cmath>
#include <glm/gtx/vector_angle.hpp>

DefenseManager& DefenseManager::getDefenseManager(){
	static DefenseManager *defenseManager = NULL;
	if (defenseManager == NULL)
	{
		defenseManager = new DefenseManager();
	}
	return *defenseManager;
}

void DefenseManager::destroyDefenseManager()
{
	DefenseManager *defenseManager = &getDefenseManager();
	delete defenseManager;
}

std::map<std::string, Defender*>* DefenseManager::getDefenders(){
	return defenders;
}

DefenseManager::DefenseManager(){
	enemyDamage = 20;
	defenders = new std::map<std::string, Defender*>();
	enemyManager = &EnemyManager::getEnemyManager();
	cameraManager = &CameraManager::getCameraManager();
}

DefenseManager::~DefenseManager(){
	for (map<string, Defender *>::iterator iterator = defenders->begin(); iterator != defenders->end(); iterator++)
	{
		delete (*iterator).second;
	}
	delete defenders;
}

void DefenseManager::addDefender(){	
	float x = cameraManager->getCurrentCamera()->getPosition().x;
	float y = 0;
	float z = cameraManager->getCurrentCamera()->getPosition().z;

	ModelObject *object = new ModelObject(scene->getModel("ratchet"), glm::vec3(x, y, z), scene->getShaderPath("VSlight"), scene->getShaderPath("FSlight"));
	object->setScale(glm::vec3(0.005f, 0.005f, 0.005f));
	object->setRotation(glm::vec3(270, 0, 0));	

	string newDefenderID = getNewId();
	SphereObject *sphereObj = new SphereObject(new Sphere(0.1, 18, 18), glm::vec3(x, y+3, z), scene->getShaderPath("VSsphere"), scene->getShaderPath("FSsphere"), glm::vec4(1.0f,1.0f,0.4f,1.0f));
	Defender *defender = new Defender(newDefenderID, object, scene->getChildren(), enemyManager->getEnemies(), sphereObj);
	(*defenders)[newDefenderID] = defender;
}

std::string DefenseManager::getNewId(){
	std::string newID = "defender";
	newID.append(std::to_string(id));
	id++;
	return newID;
}

void DefenseManager::update(){
	
	for (map<string, Defender *>::iterator iterator = defenders->begin(); iterator != defenders->end(); iterator++)
	{
		iterator->second->shot(10);
		
	}
	/*
	vector<string> *toKill = new vector<string>();
	//move enemies
	for (map<string, Enemy *>::iterator iterator = enemies->begin(); iterator != enemies->end(); iterator++)
	{
		//move enemy and react if hit megatron
		if (iterator->second->move(0.005f)){
			//add to kill list 
			toKill->push_back(iterator->second->getID());
			Player *player = &Player::getPlayer();
			player->reduceHealth(playerDamage);
		}
	}

	//kill 
	for each (std::string kill in (*toKill))
	{
		(*enemies)[kill]->~Enemy();
		(*enemies).erase(kill);
	}
	delete toKill;

	//add new enemy
	double time = glfwGetTime();
	if ((time - lastNewEnemyTime) > delay){
		addEnemy();
		lastNewEnemyTime = glfwGetTime();
	}*/
}

void DefenseManager::setScene(Scene *scene){
	this->scene = scene;
}
Scene *DefenseManager::getScene(){
	return scene;
}
