#include "Object.h"
#include "Camera.h"
#include "CameraManager.h"
#include "LightManager.h"
#include <glm/gtx/string_cast.hpp>
#include "glm/gtc/type_ptr.hpp"

void Object::draw(){
	if (type == MODEL){
		model->draw(shader);
	} else
	if (type == SIMPLE_MODEL){
		simpleModel->draw(shader);
	}	
}

void Object::configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	gameModel = model;
	gameView = view;
	gameProjection = projection;
	shader->use();		

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	Camera *currentCamera = cameraManager->getCurrentCamera();
	LightManager *lightManager = &LightManager::getLightManager();	

	glUniform3f(shader->getUniformLocation("viewPos"), currentCamera->Position.x, currentCamera->Position.y, currentCamera->Position.z);
	
	glUniformMatrix4fv(shader->getUniformLocation("model"), 1, false, glm::value_ptr(gameModel));
	glUniformMatrix4fv(shader->getUniformLocation("view"), 1, false, glm::value_ptr(gameView));
	glUniformMatrix4fv(shader->getUniformLocation("projection"), 1, false, glm::value_ptr(gameProjection));		
	
	for (unsigned int i = 0; i < lightManager->getPointLights()->size(); i++){		
		PointLight light = *(*lightManager->getPointLights())[i];				
		glUniform3f(glGetUniformLocation(shader->Program, getUniformName(i, "position").c_str()), light.getPosition().x, light.getPosition().y, light.getPosition().z);
		glUniform3f(glGetUniformLocation(shader->Program, getUniformName(i, "ambient").c_str()), light.getAmbient().x, light.getAmbient().y, light.getAmbient().z);
		glUniform3f(glGetUniformLocation(shader->Program, getUniformName(i, "diffuse").c_str()), light.getDiffuse().x, light.getDiffuse().y, light.getDiffuse().z);
		glUniform3f(glGetUniformLocation(shader->Program, getUniformName(i, "specular").c_str()), light.getSpecular().x, light.getSpecular().y, light.getSpecular().z);
		glUniform1f(glGetUniformLocation(shader->Program, getUniformName(i, "constant").c_str()), light.getConstant());
		glUniform1f(glGetUniformLocation(shader->Program, getUniformName(i, "linear").c_str()), light.getLinear());
		glUniform1f(glGetUniformLocation(shader->Program, getUniformName(i, "quadratic").c_str()), light.getQuadratic());
	}	

	DirLight dirLight = lightManager->getDirLight();
	glUniform3f(glGetUniformLocation(shader->Program, "dirLight.direction"), dirLight.direction.x, dirLight.direction.y, dirLight.direction.z);
	glUniform3f(glGetUniformLocation(shader->Program, "dirLight.ambient"), dirLight.ambient.x, dirLight.ambient.y, dirLight.ambient.z);
	glUniform3f(glGetUniformLocation(shader->Program, "dirLight.diffuse"), dirLight.diffuse.x, dirLight.diffuse.y, dirLight.diffuse.z);
	glUniform3f(glGetUniformLocation(shader->Program, "dirLight.specular"), dirLight.specular.x, dirLight.specular.y, dirLight.specular.z);
}

string Object::getUniformName(int id, string part){
	string name = "pointLights[";
	name.append(to_string(id));
	name.append("].");
	name.append(part);	
	return name;
}


Model *Object::getModel(){
	return model;
}
void Object::setModel(Model *newModel){
	model = newModel;
}

glm::vec3 Object::getMovementDirection(){
	return movementDirection;
}
void Object::setMovementDirection(glm::vec3 newDirection){
	movementDirection = newDirection;
}

glm::vec3 Object::getPosition(){
	return position;
}
void Object::setPosition(glm::vec3 newPosition){
	position = newPosition;
}

glm::vec3 Object::getScale(){
	return scale;
}
void Object::setScale(glm::vec3 newScale){
	scale = newScale;
}

glm::vec3 Object::getRotation(){
	return rotation;
}
void Object::setRotation(glm::vec3 newRotation){
	rotation = newRotation;
}

glm::vec3 Object::getVelocity(){
	return velocity;
}
void Object::setVelocity(glm::vec3 newVelocity){
	velocity = newVelocity;
}

glm::vec3 Object::getScaleVelocity(){
	return scaleVelocity;
}
void Object::setScaleVelocity(glm::vec3 newVelocity){
	scaleVelocity = newVelocity;
}

glm::vec3 Object::getRotationVelocity(){
	return rotationVelocity;
}
void Object::setRotationVelocity(glm::vec3 newRotationVelocity){
	rotationVelocity = newRotationVelocity;
}

glm::vec3 Object::getEyeVector(){
	return eyeVector;
}
void Object::setEyeVector(glm::vec3 newEyeVector){
	eyeVector = newEyeVector;
}

glm::vec3 Object::getUpVector(){
	return upVector;
}
void Object::setUpVector(glm::vec3 newUpVector){
	upVector = newUpVector;
}

Object::Object(Model *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath) :
model(model), position(position), scale(glm::vec3(1.0f, 1.0f, 1.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)), 
velocity(glm::vec3(0.0f, 0.0f, 0.0f)), scaleVelocity(glm::vec3(0.0f, 0.0f, 0.0f)), rotationVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
eyeVector(glm::vec3(0.0f, 0.0f, 0.0f)), upVector(glm::vec3(0.0f, 0.0f, 0.0f)), type(MODEL){
	shader = new Shader(vertexPath, fragmentPath);
}

Object::Object(SimpleModel *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath) :
simpleModel(model), position(position), scale(glm::vec3(1.0f, 1.0f, 1.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
velocity(glm::vec3(0.0f, 0.0f, 0.0f)), scaleVelocity(glm::vec3(0.0f, 0.0f, 0.0f)), rotationVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
eyeVector(glm::vec3(0.0f, 0.0f, 0.0f)), upVector(glm::vec3(0.0f, 0.0f, 0.0f)), type(SIMPLE_MODEL){
	shader = new Shader(vertexPath, fragmentPath);
}


Object::~Object(){	
}