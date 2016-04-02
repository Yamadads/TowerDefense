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
	loadModels();
	initShadersPaths();
		
	SceneObject *object = NULL;	
	SimpleModel *simpleModel = NULL;

	initMap(object, paths["VSlight"], paths["FSlight"], paths["VSsimple"], paths["FSsimple"]);

	object = new ModelObject(models["megatron"], glm::vec3(0.0f, 0.0f, 0.0f), paths["VSlight"], paths["FSlight"]);
	object->setRotation(glm::vec3(270.0f, 0.0f, 0.0f));
	object->setScale(glm::vec3(0.008f, 0.008f, 0.008f));
	(*children)["megatron"] = object;	

	Camera *camera = new Camera(CameraPosition);
	InputManager *inputManager = &InputManager::getInputManager();
	inputManager->setCurrentCamera(camera);

	CameraManager *cameraManager = &CameraManager::getCameraManager();
	cameraManager->setCurrentCamera(camera);

}

void Scene::loadModels(){
	models["megatron"] = new Model("Models/Megatron/RB-Megatron.obj");
	models["raptor"] = new Model("Models/FA-22_Raptor/FA-22_Raptor.obj");
	models["ratchet"] = new Model("Models/Ratchet/RB-Ratchet.obj");
}

void Scene::initShadersPaths(){	
	paths["VSmodel"] = "Shaders/model.vs";
	paths["FSmodel"] = "Shaders/model.frag";
	paths["VSsimple"] = "Shaders/simpleModel.vs";
	paths["FSsimple"] = "Shaders/simpleModel.frag";
	paths["VSlight"] = "Shaders/LightShader.vs";
	paths["FSlight"] = "Shaders/LightShader.frag";
	paths["VSsphere"] = "Shaders/Sphere.vs";
	paths["FSsphere"] = "Shaders/Sphere.frag";
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

	for (map<string, Model *>::iterator iterator = models.begin(); iterator != models.end(); iterator++)
	{
		delete (*iterator).second;
	}
}

Model *Scene::getModel(std::string name){
	return models[name];
}

map<string, SceneObject *>* Scene::getChildren()
{
	return children;
}

const GLchar* Scene::getShaderPath(string name){
	return paths[name];
}