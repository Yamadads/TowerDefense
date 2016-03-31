#pragma once
#include "SceneObject.h"

#include <map>

#include <GLFW/glfw3.h>

class Scene
{
private:
	std::map<std::string, SceneObject *> *children;
	std::map<std::string, GLchar*> paths;

	void initMap(SceneObject *object, const GLchar* floorVSPath, const GLchar* floorFSPath, const GLchar* wallVSPath, const GLchar* wallFSPath);
public:
	std::map<std::string, SceneObject *> *getChildren();
	const GLchar* getShaderPath(std::string name);

	Scene();
	~Scene();
};

