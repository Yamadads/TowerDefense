#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class PointLight {
private:
	glm::vec3 position;

	float constant;
	float linear;
	float quadratic;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

public:
	PointLight(glm::vec3 position, float constant, float linear, float quadratic, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	PointLight(glm::vec3 lightPosition);
	PointLight();
	~PointLight();	

	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);

	float getConstant();
	float getLinear();
	float getQuadratic();

	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpecular();
};