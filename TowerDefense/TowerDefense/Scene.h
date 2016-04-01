#pragma once
#include "SceneObject.h"

#include <map>
#include "Model.h"
#include <GLFW/glfw3.h>

class Scene
{
private:
	std::map<std::string, SceneObject *> *children;
	std::map<std::string, GLchar*> paths;
	std::map<std::string, Model*> models;

	void loadModels();
	void initShadersPaths();
	void initMap(SceneObject *object, const GLchar* floorVSPath, const GLchar* floorFSPath, const GLchar* wallVSPath, const GLchar* wallFSPath);
public:
	Model *getModel(std::string name);
	std::map<std::string, SceneObject *> *getChildren();
	const GLchar* getShaderPath(std::string name);

	Scene();
	~Scene();
};

