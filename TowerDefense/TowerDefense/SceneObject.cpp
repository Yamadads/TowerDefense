#include "SceneObject.h"

Shader *SceneObject::getShader(){
	return shader;
}

void SceneObject::setShader(Shader *newShader){
	shader = newShader;
}

glm::mat4 SceneObject::getGameModel(){
	return gameModel;
}
void SceneObject::setGameModel(glm::mat4 model){
	gameModel = model;
}

glm::mat4 SceneObject::getGameView(){
	return gameView;
}

void SceneObject::setGameView(glm::mat4 view){
	gameView = view;
}

glm::mat4 SceneObject::getGameProjection(){
	return gameProjection;
}

void SceneObject::setGameProjection(glm::mat4 projection){
	gameProjection = projection;
}

glm::vec3 SceneObject::getMovementDirection(){
	return movementDirection;
}
void SceneObject::setMovementDirection(glm::vec3 newDirection){
	movementDirection = newDirection;
}

glm::vec3 SceneObject::getPosition(){
	return position;
}
void SceneObject::setPosition(glm::vec3 newPosition){
	position = newPosition;
}

glm::vec3 SceneObject::getScale(){
	return scale;
}
void SceneObject::setScale(glm::vec3 newScale){
	scale = newScale;
}

glm::vec3 SceneObject::getRotation(){
	return rotation;
}
void SceneObject::setRotation(glm::vec3 newRotation){
	rotation = newRotation;
}

glm::vec3 SceneObject::getVelocity(){
	return velocity;
}
void SceneObject::setVelocity(glm::vec3 newVelocity){
	velocity = newVelocity;
}

glm::vec3 SceneObject::getScaleVelocity(){
	return scaleVelocity;
}
void SceneObject::setScaleVelocity(glm::vec3 newVelocity){
	scaleVelocity = newVelocity;
}

glm::vec3 SceneObject::getRotationVelocity(){
	return rotationVelocity;
}
void SceneObject::setRotationVelocity(glm::vec3 newRotationVelocity){
	rotationVelocity = newRotationVelocity;
}

glm::vec3 SceneObject::getEyeVector(){
	return eyeVector;
}
void SceneObject::setEyeVector(glm::vec3 newEyeVector){
	eyeVector = newEyeVector;
}

glm::vec3 SceneObject::getUpVector(){
	return upVector;
}
void SceneObject::setUpVector(glm::vec3 newUpVector){
	upVector = newUpVector;
}