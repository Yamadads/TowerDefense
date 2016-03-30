#define _USE_MATH_DEFINES
#include <cmath>
#include "Sphere.h"

Sphere::Sphere(float radius, int slices, int stacks) :radius(radius), slices(slices), stacks(stacks)
{
	makeVertices();
	makeIndices();
}

Sphere::~Sphere()
{
}

void Sphere::makeVertices()
{
	float const R = 1.0f / (slices - 1);
	float const S = 1.0f / (stacks - 1);
	int count = 0;

	for (int r = 0; r < slices; ++r) {
		for (int s = 0; s < stacks; ++s) {
			float const y = (float)(sin(-M_PI_2 + M_PI * r * R));
			float const x = (float)(cos(2 * M_PI * s * S) * sin(M_PI * r  * R));
			float const z = (float)(sin(2 * M_PI * s * S) * sin(M_PI * r  * R));

			vertices.push_back(vec3(x, y, z)*radius);
			count++;
		}
	}
}

void Sphere::makeIndices()
{
	for (int r = 0; r < slices; ++r) {
		for (int s = 0; s < stacks; ++s) {
			int curRow = r * stacks;
			int nextRow = (r + 1) * stacks;
			indices.push_back(curRow + s);
			indices.push_back(nextRow + s);
			indices.push_back(nextRow + (s + 1));

			indices.push_back(curRow + s);
			indices.push_back(nextRow + (s + 1));
			indices.push_back(curRow + (s + 1));
		}
	}
}

float Sphere::getRadius()
{
	return radius;
}

vector<vec3> Sphere::getVertives()
{
	return vertices;
}

vector<GLuint> Sphere::getIndices()
{
	return indices;
}

int Sphere::GetTotalVertices()
{
	return slices*stacks;
}

int Sphere::GetTotalIndices()
{
	return slices*stacks * 2 * 3;
}