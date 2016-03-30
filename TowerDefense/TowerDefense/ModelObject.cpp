#include "ModelObject.h"
#include "Camera.h"
#include "CameraManager.h"
#include "LightManager.h"
#include <glm/gtx/string_cast.hpp>
#include "glm/gtc/type_ptr.hpp"

void ModelObject::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	configShader(model, view, projection);
	this->model->draw(getShader());
}

void ModelObject::configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
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
	
	glUniform1i(glGetUniformLocation(getShader()->Program, "pointsNumber"), (GLint)lightManager->getPointLights()->size());

	for (unsigned int i = 0; i < lightManager->getPointLights()->size(); i++){		
		PointLight light = *(*lightManager->getPointLights())[i];				
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(i, "position").c_str()), light.getPosition().x, light.getPosition().y, light.getPosition().z);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(i, "ambient").c_str()), light.getAmbient().x, light.getAmbient().y, light.getAmbient().z);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(i, "diffuse").c_str()), light.getDiffuse().x, light.getDiffuse().y, light.getDiffuse().z);
		glUniform3f(glGetUniformLocation(getShader()->Program, getUniformName(i, "specular").c_str()), light.getSpecular().x, light.getSpecular().y, light.getSpecular().z);
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(i, "constant").c_str()), light.getConstant());
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(i, "linear").c_str()), light.getLinear());
		glUniform1f(glGetUniformLocation(getShader()->Program, getUniformName(i, "quadratic").c_str()), light.getQuadratic());
	}	

	DirLight dirLight = lightManager->getDirLight();
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.direction"), dirLight.direction.x, dirLight.direction.y, dirLight.direction.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.ambient"), dirLight.ambient.x, dirLight.ambient.y, dirLight.ambient.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.diffuse"), dirLight.diffuse.x, dirLight.diffuse.y, dirLight.diffuse.z);
	glUniform3f(glGetUniformLocation(getShader()->Program, "dirLight.specular"), dirLight.specular.x, dirLight.specular.y, dirLight.specular.z);
}

string ModelObject::getUniformName(int id, string part){
	string name = "pointLights[";
	name.append(to_string(id));
	name.append("].");
	name.append(part);	
	return name;
}


Model *ModelObject::getModel(){
	return model;
}
void ModelObject::setModel(Model *newModel){
	model = newModel;
}

ModelObject::ModelObject(Model *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath){
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

ModelObject::~ModelObject(){
	delete model;
	delete getShader();
}