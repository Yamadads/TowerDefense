#include "CameraManager.h"


CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}


Camera* CameraManager::getCurrentCamera()
{
	return currentCamera;
}


void CameraManager::setCurrentCamera(Camera *newCamera)
{
	currentCamera = newCamera;
}

CameraManager& CameraManager::getCameraManager()
{
	static CameraManager *cameraManager = NULL;

	if (cameraManager == NULL){

		cameraManager = new CameraManager();
	}
	return *cameraManager;
}

void CameraManager::destroyCameraManager()
{
	CameraManager *cameraManager = &getCameraManager();
	delete cameraManager;
}