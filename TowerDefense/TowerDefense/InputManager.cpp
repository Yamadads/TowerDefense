#include "InputManager.h"
#include "GameManager.h"
#include <algorithm>

using namespace std;

InputManager::InputManager()
:window(glfwGetCurrentContext()), mouseLastX(DefaultWidth / 2.0), mouseLastY(DefaultHeight / 2.0), firstMouse(true),
deltaTime(0.0f), lastFrame(0.0f)
{
	defenseManager = &DefenseManager::getDefenseManager();
	isNewDefender = false;
}

InputManager::~InputManager()
{
}

void InputManager::update()
{
	GLfloat currentFrame = (GLfloat)glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	if (currentCamera != NULL && glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		if (glfwGetKey(window, GLFW_KEY_W))
			currentCamera->ProcessKeyboard(FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S))
			currentCamera->ProcessKeyboard(BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A))
			currentCamera->ProcessKeyboard(LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D))
			currentCamera->ProcessKeyboard(RIGHT, deltaTime);
	}
}



void InputManager::setCurrentCamera(Camera *newCamera)
{
	currentCamera = newCamera;
}


void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){
		if (!isNewDefender){
			Player *player = &Player::getPlayer();
			if ((defenseManager->getDefenders()->size() == 0) || ((player->getPoints() / defenseManager->getDefenders()->size()) > 5)){
				defender = defenseManager->addDefender();
				defender->activate();
				defender = NULL;
			}			
		}
	}
		
}



void InputManager::keyCallbackFun(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	InputManager *inputManager = new InputManager();
	inputManager->keyCallback(window, key, scancode, action, mode);
}


void InputManager::mouseCallback(GLFWwindow* window, double xpos, double ypos)
{

	if (firstMouse)
	{
		mouseLastX = (GLfloat)xpos;
		mouseLastY = (GLfloat)ypos;
		firstMouse = false;
	}

	GLfloat xoffset = (GLfloat)xpos - mouseLastX;
	GLfloat yoffset = mouseLastY - (GLfloat)ypos;

	mouseLastX = (GLfloat)xpos;
	mouseLastY = (GLfloat)ypos;



	currentCamera->ProcessMouseMovement(xoffset, yoffset);

}

void InputManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void InputManager::mouseCallbackFun(GLFWwindow* window, double xpos, double ypos)
{
	InputManager *inputManager = &getInputManager();
	inputManager->mouseCallback(window, xpos, ypos);
}

void InputManager::mouseButtonCallbackFun(GLFWwindow* window, int button, int action, int mods)
{
	InputManager *inputManager = &getInputManager();
	inputManager->mouseButtonCallback(window, button, action, mods);
}


void InputManager::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	currentCamera->ProcessMouseScroll((GLfloat)yoffset);
}

void InputManager::scrollCallbackFun(GLFWwindow* window, double xoffset, double yoffset)
{
	InputManager *inputManager = &getInputManager();
	inputManager->scrollCallback(window, xoffset, yoffset);
}


InputManager& InputManager::getInputManager()
{
	static InputManager *inputManager = NULL;

	if (inputManager == NULL)
	{
		glfwSetKeyCallback(glfwGetCurrentContext(), *keyCallbackFun);
		glfwSetScrollCallback(glfwGetCurrentContext(), *scrollCallbackFun);
		glfwSetCursorPosCallback(glfwGetCurrentContext(), *mouseCallbackFun);
		glfwSetMouseButtonCallback(glfwGetCurrentContext(), *mouseButtonCallbackFun);

		glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		inputManager = new InputManager();
	}

	return *inputManager;
}

void InputManager::destroyInputManager()
{
	InputManager *inputManager = &getInputManager();
	delete inputManager;
}
