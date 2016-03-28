#pragma once
#include "Model.h"
#include "SimpleModel.h"
#include "Shader.h"
#include <vector>

enum ObjectType {
	MODEL,
	SIMPLE_MODEL
};

class Object
{
private:	
	Model *model = nullptr;
	SimpleModel *simpleModel = nullptr;
	Shader *shader = nullptr;

	ObjectType type;

	glm::mat4 gameModel;
	glm::mat4 gameView;
	glm::mat4 gameProjection;

	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	glm::vec3 movementDirection;

	glm::vec3 velocity;
	glm::vec3 scaleVelocity;
	glm::vec3 rotationVelocity;

	glm::vec3 eyeVector;
	glm::vec3 upVector;

	string getUniformName(int id, string part);
public:
	void draw();
	void configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	Object(Model *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath);
	Object(SimpleModel *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath);
	~Object();

	Model *getModel();
	void setModel(Model *newModel);

	glm::vec3 getMovementDirection();
	void setMovementDirection(glm::vec3 newDirection);

	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);

	glm::vec3 getScale();
	void setScale(glm::vec3 newScale);

	glm::vec3 getRotation();
	void setRotation(glm::vec3 newRotation);

	glm::vec3 getVelocity();
	void setVelocity(glm::vec3 newVelocity);

	glm::vec3 getScaleVelocity();
	void setScaleVelocity(glm::vec3 newVelocity);

	glm::vec3 getRotationVelocity();
	void setRotationVelocity(glm::vec3 newRotationVelocity);

	glm::vec3 getEyeVector();
	void setEyeVector(glm::vec3 newEyeVector);

	glm::vec3 getUpVector();
	void setUpVector(glm::vec3 newUpVector);
};

