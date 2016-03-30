#pragma once
#define GLM_FORCE_RADIANS
// GLFW
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

using namespace std;
using namespace glm;

class Sphere
{
private:

	float radius;
	int slices, stacks;

	void makeVertices();
	void makeIndices();
	vector <vec3> vertices;
	vector <GLuint> indices;


public:
	Sphere(float radius, int slices, int stacks);
	~Sphere();	

	float getRadius();

	vector <vec3> getVertives();
	vector <GLuint> getIndices();

	int GetTotalVertices();
	int GetTotalIndices();
};

