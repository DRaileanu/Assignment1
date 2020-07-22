//------------------------------------------------------
// Polyhedron subdividing icosahedron (20 tris) by N-times iteration
// The icosphere with N=1 (default) has 80 triangles by subdividing a triangle
// of icosahedron into 4 triangles. If N=0, it is identical to icosahedron.
// AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// Source: http://www.songho.ca/opengl/gl_sphere.html
// CREATED: 2018-07-23
// MODIFIED: 2020-07-22 by Dan Raileanu
//-------------------------------------------------------


#pragma once
#include "Drawable.h"
#include <glm/gtc/type_ptr.hpp>


class Sphere : public Drawable {
public:
	Sphere(float radius, int subdivisions);
	~Sphere();

private:
	float radius;
	int subdivision;

private:

	//methods to build IcoSphere from Icosahedron
	std::vector<float> computeIcosahedronVertices();
	void addVertices(const float v1[3], const float v2[3], const float v3[3]);
	void addIndices(unsigned int, unsigned int, unsigned int);
	void buildVerticesFlat();
	void subdivideVerticesFlat();
	void computeHalfVertex(const float v1[3], const float v2[3], float length, float newV[3]);
	float computeScaleForLength(const float v[3], float length);

	//note that the Icosahedron will have vertices defined as tightly packed floats instead of glm::vec3 as the Sphere, so have to reinterpret in Sphere constructor
	std::vector<float> icosahedronVertices;

};


