#include "SphereObject.h"
#include "Camera.h"
#include "CameraManager.h"
#include "LightManager.h"
#include <glm/gtx/string_cast.hpp>
#include "glm/gtc/type_ptr.hpp"

void SphereObject::draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	configShader(model, view, projection);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, sphere->GetTotalIndices(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void SphereObject::configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection){
	setGameModel(model);
	setGameView(view);
	setGameProjection(projection);

	getShader()->use();

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	Camera *currentCamera = cameraManager->getCurrentCamera();
	LightManager *lightManager = &LightManager::getLightManager();

	glUniformMatrix4fv(getShader()->getUniformLocation("model"), 1, false, glm::value_ptr(getGameModel()));
	glUniformMatrix4fv(getShader()->getUniformLocation("view"), 1, false, glm::value_ptr(getGameView()));
	glUniformMatrix4fv(getShader()->getUniformLocation("projection"), 1, false, glm::value_ptr(getGameProjection()));

	glUniform4f(getShader()->getUniformLocation("uColor"), uColor.x, uColor.y, uColor.z, uColor.w);	
}

void SphereObject::setupVAO(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sphere->getVertives().size() * sizeof(vec3), sphere->getVertives().data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphere->getIndices().size() * sizeof(GLuint), sphere->getIndices().data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0); // Unbind VAO
}

Sphere *SphereObject::getSphere(){
	return sphere;
}
void SphereObject::setSphere(Sphere *newSphere){
	sphere = newSphere;
	setupVAO();
}

SphereObject::SphereObject(Sphere *sphere, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath, glm::vec4 color){
	setShader(new Shader(vertexPath, fragmentPath));
	setSphere(sphere);
	setPosition(position);
	setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	setVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setScaleVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setRotationVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	setEyeVector(glm::vec3(0.0f, 0.0f, 0.0f));
	setUpVector(glm::vec3(0.0f, 0.0f, 0.0f));
	setColor(color);
	setupVAO();
}

SphereObject::~SphereObject(){
	delete sphere;	
	delete getShader();
}

glm::vec4 SphereObject::getColor(){
	return uColor;
}

void SphereObject::setColor(glm::vec4 color){
	uColor = color;
}