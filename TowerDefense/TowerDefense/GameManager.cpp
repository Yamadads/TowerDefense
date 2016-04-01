#include "GameManager.h"

#include "Settings.h"
#include <time.h>
#include <fstream>

GLuint GameManager::screenHeight = 0;
GLuint GameManager::screenWidth = 0;
bool GameManager::running = false;

GameManager::GameManager():window(glfwGetCurrentContext())
{
	cameraManager = &CameraManager::getCameraManager();
	inputManager = &InputManager::getInputManager();
	renderManager = &RenderManager::getRenderManager();
	scene = new Scene();
	player = &Player::getPlayer();
	enemyManager = &EnemyManager::getEnemyManager();
	enemyManager->setScene(scene);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(window);
	running = true;
}

GameManager & GameManager::getGameManager()
{
	static GameManager *gameManager = NULL;

	if (gameManager != NULL){
		return *gameManager;
	}

	srand((unsigned int)time(NULL));

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLuint monitorWidth = videoMode->width;
	GLuint monitorHeight = videoMode->height;
	GLuint centerX = monitorWidth / 2;
	GLuint centerY = monitorHeight / 2;

	char fullScreen;
	do{
		system("cls");
		cout << "Do you want fullscreen? (y/n)" << endl;
		cin >> fullScreen;
	} while ((fullScreen != 'y') && (fullScreen != 'n'));

	if (fullScreen == 'y')
	{
		GLFWwindow* window = glfwCreateWindow(monitorWidth, monitorHeight, "TowerDefense", glfwGetPrimaryMonitor(), nullptr);
		glfwMakeContextCurrent(window);
		screenWidth = monitorWidth;
		screenHeight = monitorHeight;
	}
	else if (fullScreen == 'n')
	{
		GLFWwindow* window = glfwCreateWindow(DefaultWidth, DefaultHeight, "TowerDefense", nullptr, nullptr);
		glfwSetWindowPos(window, centerX - (DefaultWidth / 2), centerY - (DefaultHeight / 2));
		glfwMakeContextCurrent(window);
		screenWidth = DefaultWidth;
		screenHeight = DefaultHeight;
	}

	glewExperimental = GL_TRUE;
	glewInit();

	gameManager = new GameManager();
	return *gameManager;
}

GameManager::~GameManager()
{
	CameraManager::destroyCameraManager();
	InputManager::destroyInputManager();
	RenderManager::destroyRenderManager();	
	EnemyManager::destroyEnemyManager();
	Player::destroyPlayer();
	delete scene;
}

void GameManager::destroyGameManager()
{
	GameManager *gameManager = &getGameManager();
	delete gameManager;

	GLFWwindow* window = glfwGetCurrentContext();
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GameManager::runGameLoop()
{
	cout << running << endl;
	GLfloat lastTime = (GLfloat)glfwGetTime();
	deltaTime = 0.0f;

	while (running)
	{				
		GLfloat currentTime = (GLfloat)glfwGetTime();
		deltaTime += (currentTime - lastTime) * GameSpeed;
		lastTime = currentTime;

		glfwPollEvents();
		inputManager->update();
		enemyManager->update();

		renderManager->render(scene->getChildren(),screenWidth, screenHeight);
		
		running = !glfwWindowShouldClose(window);
		checkPlayer();
	}
}

void GameManager::checkPlayer(){
	if (player->getHealth() == 0){
		running = false;
	}
}