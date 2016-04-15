#include <iostream>

#include <GL/glew.h>
#include "CameraManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "LightManager.h"
#include "Scene.h"
#include "EnemyManager.h"
#include "DefenseManager.h"
#include "Player.h"
#include <GLFW/glfw3.h>

using namespace std;

class GameManager{
private:
	static bool running;

	GLFWwindow *window;
	GLfloat deltaTime;

	CameraManager *cameraManager;
	InputManager *inputManager;
	RenderManager *renderManager;
	LightManager *lightManager;
	EnemyManager *enemyManager;
	DefenseManager *defenseManager;
	Scene *scene;
	Player *player;

	GameManager();
	GameManager(const GameManager &);

	~GameManager();

	void checkPlayer();
public:
	static GLuint screenWidth;
	static GLuint screenHeight;

	void runGameLoop();
	static GameManager & getGameManager();
	static void destroyGameManager();
};