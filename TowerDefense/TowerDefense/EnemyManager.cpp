#include "EnemyManager.h"
#include "ModelObject.h"
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
	enemies = new std::map<std::string, Enemy*>();
	this->scene = scene;
	model = new Model("Models/FA-22_Raptor/FA-22_Raptor.obj");
}

EnemyManager::~EnemyManager(){

}

void EnemyManager::addEnemy(){
	double radius = 55;
	double angle = rand()*3.1415 * 2;
	double x = cos(angle)*radius;
	double y = 2;
	double z = sin(angle)*radius;
	 
	ModelObject *object = new ModelObject(model, glm::vec3(x, y, z), scene->getShaderPath("VSlight"), scene->getShaderPath("FSlight"));

	object->setScale(glm::vec3(0.2f, 0.2f, 0.2f));	

	glm::vec3 targetPosition = (*(scene->getChildren()))["megatron"]->getPosition();		
	glm::vec2 u = glm::vec2(0,-1);
	glm::vec2 v = glm::normalize(glm::vec2(targetPosition.x,targetPosition.z)-glm::vec2(x,z)); 
	GLfloat angle2 = -1 * 180 / 3.14 * fmodf(atan2(u.x*v.y - v.x*u.y, u.x*v.x + u.y*v.y), 2 * 3.14);	
	object->setRotation(glm::vec3(270, 0, angle2));

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

void EnemyManager::update(){		
	double time = glfwGetTime();
	if ((time - lastNewEnemyTime) > delay){
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
