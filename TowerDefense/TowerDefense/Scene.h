#pragma once
#include "Object.h"
#include <vector>

#include <GLFW/glfw3.h>



class Scene
{
private:
	vector<Object *> *children;
	void initMap(Object *object, SimpleModel *simpleModel, const GLchar* vertexPath, const GLchar* fragmentPath);
public:
	vector<Object *> *getChildren();

	Scene();
	~Scene();
};

