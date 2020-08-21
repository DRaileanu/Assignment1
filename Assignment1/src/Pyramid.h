#pragma once
#include "Drawable.h"

class Pyramid : public Drawable {
public:
	Pyramid() {
		vertices = {
			glm::vec3(-0.5,-0.5,-0.5),
			glm::vec3(0.5,-0.5,-0.5),
			glm::vec3(0.5,-0.5,+0.5),

			glm::vec3(-0.5,-0.5,-0.5),
			glm::vec3(0.5,-0.5,0.5),
			glm::vec3(-0.5,-0.5,0.5),

			glm::vec3(-0.5,-0.5,0.5),
			glm::vec3(0.5,-0.5,0.5),
			glm::vec3(0.0,0.5,0.0),

			glm::vec3(0.5,-0.5,0.5),
			glm::vec3(0.5,-0.5,-0.5),
			glm::vec3(0.0,0.5,0.0),

			glm::vec3(0.5,-0.5,-0.5),
			glm::vec3(-0.5,-0.5,-0.5),
			glm::vec3(0.0,0.5,0.0),

			glm::vec3(-0.5,-0.5,-0.5),
			glm::vec3(-0.5,-0.5,0.5),
			glm::vec3(0.0,0.5,0.0),
		};
		colours = {
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),

			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),

			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),

			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),

			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),

			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 0.0f)
		};

		setupBufferData();
	}
	~Pyramid() {}

};