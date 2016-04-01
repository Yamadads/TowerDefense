#include "ModelObject.h"
#include "SphereObject.h"
#include "Enemy.h"
#include <map>

class Defender{
private:
	std::string objectID;
	std::string bulletID;

	ModelObject *object;
	SphereObject *bullet;

	std::map<std::string, SceneObject *> *objects;
	std::map<std::string, Enemy *> *enemies;

	Enemy *tempEnemy = NULL;

public:
	Defender(std::string id, ModelObject *defenderObject, std::map<std::string, SceneObject *> *sceneObjects, std::map<std::string, Enemy *> *enemies, SphereObject *sphereObject);
	~Defender();

	bool move(float speed);
	ModelObject *getObject();
	SphereObject *getBullet();

	void shot(int hitScore);

	std::string getID();
};