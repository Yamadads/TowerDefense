#pragma once
#include "Object.h"
#include <vector>

#include <GLFW/glfw3.h>



class Scene
{
private:
	vector<Object *> *children;
	void initMap(Object *object, SimpleModel *simpleModel, const GLchar* floorVSPath, const GLchar* floorFSPath,const GLchar* wallVSPath, const GLchar* wallFSPath);
public:
	vector<Object *> *getChildren();

	Scene();
	~Scene();
};

