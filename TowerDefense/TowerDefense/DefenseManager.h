#pragma once
#include <map>
#include "Scene.h"
#include "Model.h"
#include "Defender.h"
#include "Sphere.h"
#include "EnemyManager.h"
#include "CameraManager.h"

class DefenseManager{
private:
	DefenseManager();
	~DefenseManager();

	std::map<std::string, Defender*> *defenders;
	EnemyManager *enemyManager;
	CameraManager *cameraManager;
	Scene *scene;
	unsigned long long id = 0;	

	int enemyDamage;

	std::string getNewId();
public:
	void setScene(Scene *scene);
	Scene *getScene();

	std::map<std::string, Defender*> *getDefenders();

	Defender* addDefender();
	void update(double deltaTime);

	static DefenseManager& getDefenseManager();
	static void destroyDefenseManager();
};