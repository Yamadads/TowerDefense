#pragma once
#include "SceneObject.h"

#include <map>

#include <GLFW/glfw3.h>

class Scene
{
private:
	std::map<std::string, SceneObject *> *children;

	void initMap(SceneObject *object, const GLchar* floorVSPath, const GLchar* floorFSPath, const GLchar* wallVSPath, const GLchar* wallFSPath);
public:
	std::map<std::string, SceneObject *> *getChildren();

	Scene();
	~Scene();
};

