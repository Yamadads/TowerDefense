#include <iostream>
#include "GameManager.h"
#include <ctime>

int main(int argc, char **argv)
{
	srand(time(NULL));
	GameManager *gameManager = &GameManager::getGameManager();
	gameManager->runGameLoop();
	GameManager::destroyGameManager();

	return 0;
}