#pragma once
#include "Shader.h"
#include <glm\glm.hpp>

class SceneObject
{
private:
	Shader *shader = nullptr;

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

	virtual void configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection) = 0;

public:
	virtual void draw(glm::mat4& model, glm::mat4& view, glm::mat4& projection) = 0;
	
	Shader *getShader();
	void setShader(Shader *newShader);

	glm::mat4 getGameModel();
	void setGameModel(glm::mat4 model);

	glm::mat4 getGameView();
	void setGameView(glm::mat4 view);

	glm::mat4 getGameProjection();
	void setGameProjection(glm::mat4 projection);

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

