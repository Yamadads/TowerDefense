#include "SceneObject.h"
#include <map>

class Enemy{
private:
	int lifePoints;
	std::string id;
	glm::vec3 target;

	SceneObject *object;
	std::map<std::string, SceneObject *> *objects;

public:
	Enemy(std::string id, SceneObject *enemyObject, glm::vec3 target, std::map<std::string, SceneObject *> *sceneObjects);
	~Enemy();

	int getLifePoints();	
	void hit(int force);
};