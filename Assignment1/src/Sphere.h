#pragma once
#include "Drawable.h"
#include <glm/gtc/type_ptr.hpp>


class Sphere : public Drawable {
public:
	Sphere();
	~Sphere();

private:
	std::vector<float> computeIcosahedronVertices();
	void createIcosahedron();
	void addVertices(float*, float*, float*);
	void addIndices(unsigned int, unsigned int, unsigned int);
};

