#pragma once
#include <map>
#include "Enemy.h"
#include "Scene.h"
#include "Model.h"

class EnemyManager{
private:	
	EnemyManager();
	~EnemyManager();
	
	std::map<std::string, Enemy*> *enemies;
	Scene *scene;
	unsigned long long id = 0;
	double lastNewEnemyTime = 0;
	double delay = 10;
	std::string getNewId();
	Model *model;
public:
	double getDelay();
	void setDelay(double delayTime);

	void setScene(Scene *scene);
	Scene *getScene();

	std::map<std::string, Enemy*> *getEnemies();
	
	void addEnemy();
	void update();
	
	static EnemyManager& getEnemyManager();
	static void destroyEnemyManager();
};