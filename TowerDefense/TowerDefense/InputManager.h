#pragma once
#include <iostream>
#include "Camera.h"
#include <GLFW/glfw3.h>


class InputManager
{
private:

	GLfloat mouseLastX;
	GLfloat mouseLastY;
	GLfloat deltaTime;
	GLfloat lastFrame;
	bool firstMouse;
	GLfloat lastShootTime;
	glm::vec3 eyeVector;
	Camera *currentCamera;
	GLFWwindow *window;

	void generateShoot();

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouseCallback(GLFWwindow* window, double xpos, double ypos);
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	
	InputManager();
	~InputManager();

public:

	static InputManager& getInputManager();
	static void destroyInputManager();

	void update();

	void setCurrentCamera(Camera *newCamera);

	static void keyCallbackFun(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void mouseCallbackFun(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallbackFun(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallbackFun(GLFWwindow* window, double xoffset, double yoffset);
};

