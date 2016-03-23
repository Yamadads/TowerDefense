#include "Object.h"
#include "Camera.h"
#include "CameraManager.h"
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

void Object::configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::vec3 lightPosition){
	gameModel = model;
	gameView = view;
	gameProjection = projection;
	shader->use();		

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	Camera *currentCamera = cameraManager->getCurrentCamera();

	//glUniform3f(shader->getUniformLocation("viewPos"), currentCamera->Position.x, currentCamera->Position.y, currentCamera->Position.z);
	glUniform4f(shader->getUniformLocation("lightPosition"), lightPosition.x, lightPosition.y, lightPosition.z, 1);

	glUniformMatrix4fv(shader->getUniformLocation("model"), 1, false, glm::value_ptr(gameModel));
	glUniformMatrix4fv(shader->getUniformLocation("view"), 1, false, glm::value_ptr(gameView));
	glUniformMatrix4fv(shader->getUniformLocation("projection"), 1, false, glm::value_ptr(gameProjection));

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