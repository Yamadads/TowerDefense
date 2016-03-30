#pragma once
#include <iostream>
#define GLFW_INCLUDE_GLU

#include <vector>
#include "SceneObject.h"
#include "CameraManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
using namespace std;

class RenderManager
{

private:
	GLFWwindow *window;
	CameraManager *cameraManager;

	bool firstRender;
	glm::mat4 rotateModel(glm::mat4 modelMatrix,glm::vec3 rotationMatrix);
	glm::mat4 transformModel(glm::mat4 modelMatrix, SceneObject *object);

	RenderManager();
	~RenderManager();

public:
	void render(vector<SceneObject *> *objectsArray, GLuint width, GLuint height);
	static RenderManager& getRenderManager();
	static void destroyRenderManager();

};

