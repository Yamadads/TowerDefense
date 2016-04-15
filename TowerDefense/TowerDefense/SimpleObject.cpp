#include "SimpleObject.h"
#include "Camera.h"
#include "CameraManager.h"
#include "LightManager.h"
#include <glm/gtx/string_cast.hpp>
#include "glm/gtc/type_ptr.hpp"

void SimpleObject::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	configShader(model, view, projection);
	this->model->draw(getShader());
}

void SimpleObject::configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	setGameModel(model);
	setGameView(view);
	setGameProjection(projection);

	getShader()->use();

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	Camera *currentCamera = cameraManager->getCurrentCamera();
	LightManager *lightManager = &LightManager::getLightManager();

	glUniform3f(getShader()->getUniformLocation("viewPos"), currentCamera->Position.x, currentCamera->Position.y, currentCamera->Position.z);

	glUniformMatrix4fv(getShader()->getUniformLocation("model"), 1, false, glm::value_ptr(getGameModel()));
	glUniformMatrix4fv(getShader()->getUniformLocation("view"), 1, false, glm::value_ptr(getGameView()));
	glUniformMatrix4fv(getShader()->getUniformLocation("projection"), 1, false, glm::value_ptr(getGameProjection()));

	glUniform1i(glGetUniformLocation(getShader()->Program, "pointsNumber"), (GLint)lightManager->getLightPoints()->size());

	int pointNum = 0;
	float s = 0.6;
	for (std::map<unsigned long long, PointLight*>::iterator iterator = lightManager->getLightPoints()->begin(); iterator != lightManager->getLightPoints()->end(); iterator++)
	{		
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "position").c_str()), (*iterator).second->getPosition().x, (*iterator).second->getPosition().y, (*iterator).second->getPosition().z);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "ambient").c_str()), (*iterator).second->getAmbient().x*s, (*iterator).second->getAmbient().y*s, (*iterator).second->getAmbient().z*s);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "diffuse").c_str()), (*iterator).second->getDiffuse().x*s, (*iterator).second->getDiffuse().y*s, (*iterator).second->getDiffuse().z*s);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "specular").c_str()), (*iterator).second->getSpecular().x*s, (*iterator).second->getSpecular().y*s, (*iterator).second->getSpecular().z*s);
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "constant").c_str()), (*iterator).second->getConstant());
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "linear").c_str()), (*iterator).second->getLinear());
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(pointNum, "quadratic").c_str()), (*iterator).second->getQuadratic());

		pointNum++;
	}

	DirLight dirLight = lightManager->getDirLight();
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.direction"), dirLight.direction.x, dirLight.direction.y, dirLight.direction.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.ambient"), dirLight.ambient.x, dirLight.ambient.y, dirLight.ambient.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.diffuse"), dirLight.diffuse.x, dirLight.diffuse.y, dirLight.diffuse.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.specular"), dirLight.specular.x, dirLight.specular.y, dirLight.specular.z);
}

string SimpleObject::getUniformName(int id, string part){
	string name = "pointLights[";
	name.append(to_string(id));
	name.append("].");
	name.append(part);
	return name;
}


SimpleModel *SimpleObject::getModel(){
	return model;
}
void SimpleObject::setModel(SimpleModel *newModel){
	model = newModel;
}

SimpleObject::SimpleObject(SimpleModel *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath){
	setShader(new Shader(vertexPath, fragmentPath));
	setModel(model);
	setPosition(position);
	setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	setVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setScaleVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setRotationVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setEyeVector(glm::vec3(0.0f, 0.0f, 0.0f));
	setUpVector(glm::vec3(0.0f, 0.0f, 0.0f));
}

SimpleObject::~SimpleObject(){
	delete model;
	delete getShader();
}