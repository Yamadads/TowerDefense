#pragma once
#include "SimpleModel.h"
#include "Shader.h"
#include "SceneObject.h"


class SimpleObject : public SceneObject
{
private:
	SimpleModel *model = nullptr;

	string getUniformName(int id, string part);
public:
	void draw();
	void configShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection);

	SimpleObject(SimpleModel *model, glm::vec3 position, const GLchar* vertexPath, const GLchar* fragmentPath);
	~SimpleObject();

	SimpleModel *getModel();
	void setModel(SimpleModel *newModel);
};

