#pragma once
#include <iostream>
#define GLFW_INCLUDE_GLU

#include <vector>
#include "Object.h"
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
	vector<Object *> *newObjects;

	void update(vector<Object *> *objectsArray);
	void checkForNewObjects(vector<Object *> *objectArray);
	void renderTextInformation();		
	void moveToShader(Object* object, glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	bool firstRender;
	glm::mat4 rotateModel(glm::mat4 modelMatrix,glm::vec3 rotationMatrix);
	glm::mat4 transformModel(glm::mat4 modelMatrix, Object *object);

	RenderManager();
	~RenderManager();

public:

	vector<Object *> *getNewObjects();

	void setFreshRender();

	void render(vector<Object *> *objectsArray, GLuint width, GLuint height);
	static RenderManager& getRenderManager();
	static void destroyRenderManager();

};

