#pragma once
#include "Camera.h"

class CameraManager
{
private:
	Camera *currentCamera;

	CameraManager();
	~CameraManager();
public:
	

	Camera *getCurrentCamera();
	void setCurrentCamera(Camera *newCamera);

	static void destroyCameraManager();
	static CameraManager& getCameraManager();

};

