#include "PointLight.h"

PointLight::PointLight(glm::vec3 position, float constant, float linear, float quadratic, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular){
	this->position = position;
	this->ambient = ambient;
	this->constant = constant;
	this->diffuse = diffuse;
	this->linear = linear;
	this->quadratic = quadratic;
	this->specular = specular;
}
PointLight::PointLight(glm::vec3 lightPosition){
	position = lightPosition;
	ambient  = glm::vec3(0.05f, 0.05f, 0.05f);
	diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	specular = glm::vec3(1.0f, 1.0f, 1.0f);
	constant = 1.0f;
	linear = 0.09;
	quadratic = 0.032;
}
PointLight::PointLight(){
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	ambient = glm::vec3(0.05f, 0.05f, 0.05f);
	diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	specular = glm::vec3(1.0f, 1.0f, 1.0f);
	constant = 1.0f;
	linear = 0.09;
	quadratic = 0.032;
}
PointLight::~PointLight(){

}

glm::vec3 PointLight::getPosition(){
	return position;
}
void PointLight::setPosition(glm::vec3 newPosition){
	position = newPosition;
}
float PointLight::getConstant(){
	return constant;
}
float PointLight::getLinear(){
	return linear;
}
float PointLight::getQuadratic(){
	return quadratic;
}
glm::vec3 PointLight::getAmbient(){
	return ambient;
}
glm::vec3 PointLight::getDiffuse(){
	return diffuse;
}
glm::vec3 PointLight::getSpecular(){
	return specular;
}