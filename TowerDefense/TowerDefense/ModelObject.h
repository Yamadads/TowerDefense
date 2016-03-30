#pragma once
#include "Model.h"
#include "Shader.h"
#include "SceneObject.h"


class ModelObject: public SceneObject
{
private:	
	Model *model = nullptr;	

	string getUniformName(int id, string part);
public:
	void draw();
	void configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	ModelObject(Model *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath);	
	~ModelObject();

	Model *getModel();
	void setModel(Model *newModel);
};

