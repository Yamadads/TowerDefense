#pragma once
#include "SceneObject.h"

#include <vector>

#include <GLFW/glfw3.h>

class Scene
{
private:
	std::vector<SceneObject *> *children;

	void initMap(SceneObject *object, const GLchar* floorVSPath, const GLchar* floorFSPath, const GLchar* wallVSPath, const GLchar* wallFSPath);
public:
	std::vector<SceneObject *> *getChildren();

	Scene();
	~Scene();
};

