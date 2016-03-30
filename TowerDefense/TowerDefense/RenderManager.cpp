#include "RenderManager.h"
#include "SceneObject.h"
#include "GameManager.h"
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/string_cast.hpp>


void RenderManager::render(map<string, SceneObject*> *objectsArray,GLuint width, GLuint height)
{
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 projection;

	view = cameraManager->getCurrentCamera()->GetViewMatrix();
	projection = glm::perspective(glm::radians(cameraManager->getCurrentCamera()->Zoom), (GLfloat)width/ (GLfloat)height, 0.1f, 100.0f);	

	glClearColor(0.149f, 0.388f, 0.925f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	for (map<string, SceneObject *>::iterator iterator = objectsArray->begin(); iterator != objectsArray->end(); iterator++)
	{		
		glEnable(GL_DEPTH_TEST);
		SceneObject *sceneObject = (*iterator).second;
		model = transformModel(model, sceneObject);
		sceneObject->configShader(model, view, projection);
		sceneObject->draw();		
		model = glm::mat4();
	}		
	glfwSwapBuffers(window);
}

glm::mat4 RenderManager::transformModel(glm::mat4 modelMatrix, SceneObject *object){
	modelMatrix = glm::translate(modelMatrix, object->getPosition());
	modelMatrix = rotateModel(modelMatrix, object->getRotation());
	modelMatrix = glm::scale(modelMatrix, object->getScale());
	return modelMatrix;
}

glm::mat4 RenderManager::rotateModel(glm::mat4 modelMatrix, glm::vec3 rotationMatrix){
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationMatrix.x), glm::vec3(1.0f, 0.0f, 0.0f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationMatrix.y), glm::vec3(0.0f, 1.0f, 0.0f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationMatrix.z), glm::vec3(0.0f, 0.0f, 1.0f));
	return modelMatrix;
}

RenderManager::RenderManager() :window(glfwGetCurrentContext()), cameraManager(&CameraManager::getCameraManager()), firstRender(true)
{
}

RenderManager::~RenderManager()
{

}

RenderManager& RenderManager::getRenderManager()
{
	static RenderManager *renderManager = NULL;

	if (renderManager == NULL){
		renderManager = new RenderManager();

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glEnable(GL_DEPTH_TEST);
	}

	return *renderManager;
}

void RenderManager::destroyRenderManager()
{
	RenderManager *renderManager = &getRenderManager();
	delete renderManager;
}