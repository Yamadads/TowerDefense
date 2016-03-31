#include "Scene.h"
#include "Settings.h"

#include "CameraManager.h"
#include "InputManager.h"

#include "ModelObject.h"
#include "SimpleObject.h"
#include "SphereObject.h"

#include "floorMap.h"
#include "wallMap.h"


using namespace glm;

Scene::Scene()
{
	children = new map<string, SceneObject *>();	
	paths["VSmodel"] = "Shaders/model.vs";
	paths["FSmodel"] = "Shaders/model.frag";
	paths["VSsimple"] = "Shaders/simpleModel.vs";
	paths["FSsimple"] = "Shaders/simpleModel.frag";
	paths["VScolor"] = "Shaders/ColorShader.vs";
	paths["FScolor"] = "Shaders/ColorShader.frag";
	paths["VSlight"] = "Shaders/LightShader.vs";
	paths["FSlight"] = "Shaders/LightShader.frag";
	paths["VSsphere"] = "Shaders/Sphere.vs";
	paths["FSsphere"] = "Shaders/Sphere.frag";

	SceneObject *object = NULL;	
	SimpleModel *simpleModel = NULL;

	initMap(object, paths["VSlight"], paths["FSlight"], paths["VSsimple"], paths["FSsimple"]);

	object = new ModelObject(new Model("Models/Megatron/RB-Megatron.obj"), glm::vec3(0.0f, 0.0f, 0.0f), paths["VSlight"], paths["FSlight"]);
	object->setRotation(glm::vec3(270.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(0.005f, 0.005f, 0.005f));
	(*children)["megatron"] = object;	

	object = new SphereObject(new Sphere(0.5,18,18), glm::vec3(3.0f, 2.0f, 2.0f), paths["VSsphere"], paths["FSsphere"], glm::vec4(1.0f, 1.0f, 0.3f, 0.9f));
	(*children)["bullet"] = object;

	/*
	model = new Model("Models/Megatron/RB-Megatron.obj");
	object = new Object(model, glm::vec3(0.0f, 0.0f, 0.0f), paths["VSlight"], paths["FSlight"]);
	object->setRotation(glm::vec3(270.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(0.005f, 0.005f, 0.005f));
	children->push_back(object);

	model = new Model("Models/boxes/untitled.obj");
	object = new Object(model, glm::vec3(1.0f, 0.0f, -1.0f), paths["VSmodel"], paths["FSmodel"]);
	object->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(0.01f, 0.01f, 0.01f));
	children->push_back(object);

	model = new Model("Models/lamp/little_brown_lamp.obj");
	object = new Object(model, glm::vec3(0.0f, 3.0f, -5.0f), paths["VSlight"], paths["FSlight"]);
	object->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(0.1f, 0.1f, 0.1f));
	children->push_back(object);
	/*
	model = new Model("Models/tower/tower.obj");
	object = new Object(model, glm::vec3(-5.0f, 0.0f, -5.0f), paths["VSmodel"], paths["FSmodel"]);
	object->setRotation(glm::vec3(-90.0f, 0.0f, 90.0f));
	object->setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	children->push_back(object);*/



	Camera *camera = new Camera(CameraPosition);
	InputManager *inputManager = &InputManager::getInputManager();
	inputManager->setCurrentCamera(camera);

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	cameraManager->setCurrentCamera(camera);

}

void Scene::initMap(SceneObject *object, const GLchar* floorVSPath, const GLchar* floorFSPath, const GLchar* wallVSPath, const GLchar* wallFSPath){
	SimpleModel *simpleModel = NULL;

	simpleModel = new SimpleModel(floorMapVertices, sizeof(floorMapVertices), floorMapIndices, sizeof(floorMapIndices), floorMapTexture);
	object = new SimpleObject(simpleModel, glm::vec3(0.0f, 0.0f, 0.0f), floorVSPath, floorFSPath);
	object->setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	(*children)["floor"]=object;

	simpleModel = new SimpleModel(wallMapVertices, sizeof(wallMapVertices), wallMapIndices, sizeof(wallMapIndices), wallMapTexture);
	object = new SimpleObject(simpleModel, glm::vec3(0.0f, 4.0f, -40.0f), wallVSPath, wallFSPath);
	object->setRotation(glm::vec3(90.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	(*children)["wall1"] = object;

	simpleModel = new SimpleModel(wallMapVertices, sizeof(wallMapVertices), wallMapIndices, sizeof(wallMapIndices), wallMapTexture);
	object = new SimpleObject(simpleModel, glm::vec3(0.0f, 4.0f, 40.0f), wallVSPath, wallFSPath);
	object->setRotation(glm::vec3(90.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	(*children)["wall2"] = object;

	simpleModel = new SimpleModel(wallMapVertices, sizeof(wallMapVertices), wallMapIndices, sizeof(wallMapIndices), wallMapTexture);
	object = new SimpleObject(simpleModel, glm::vec3(-40.0f, 4.0f, 0.0f), wallVSPath, wallFSPath);
	object->setRotation(glm::vec3(90.0f, 0.0f, 90.0f));
	object->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	(*children)["wall3"] = object;

	simpleModel = new SimpleModel(wallMapVertices, sizeof(wallMapVertices), wallMapIndices, sizeof(wallMapIndices), wallMapTexture);
	object = new SimpleObject(simpleModel, glm::vec3(40.0f, 4.0f, 0.0f), wallVSPath, wallFSPath);
	object->setRotation(glm::vec3(90.0f, 0.0f, 90.0f));
	object->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	(*children)["wall4"] = object;
}

Scene::~Scene()
{
	for (map<string, SceneObject *>::iterator iterator = children->begin(); iterator != children->end(); iterator++)
	{
		delete (*iterator).second;
	}
	delete children;
}


map<string, SceneObject *>* Scene::getChildren()
{
	return children;
}

const GLchar* Scene::getShaderPath(string name){
	return paths[name];
}