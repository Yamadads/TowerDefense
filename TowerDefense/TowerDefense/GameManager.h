#include <iostream>

#include <GL/glew.h>
#include "CameraManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "LightManager.h"
#include "Scene.h"
#include "EnemyManager.h"
#include <GLFW/glfw3.h>

using namespace std;

class GameManager{
private:
	static bool running;
	static GLuint screenWidth;
	static GLuint screenHeight;
	GLFWwindow *window;
	GLfloat deltaTime;

	CameraManager *cameraManager;
	InputManager *inputManager;
	RenderManager *renderManager;
	LightManager *lightManager;
	EnemyManager *enemyManager;
	Scene *scene;

	GameManager();
	GameManager(const GameManager &);

	~GameManager();

public:

	void runGameLoop();
	static GameManager & getGameManager();
	static void destroyGameManager();
};