#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Mesh {
public:
	Mesh();
	~Mesh();

	virtual void draw();

protected:
	void setupBufferData();

	GLuint VAO;
	GLuint VBO;
	GLuint CBO;
	GLuint EBO;
	GLuint type;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colours;
	std::vector<unsigned int> indices;
};

