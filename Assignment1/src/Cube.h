// TODO create methods to manipulate it (translate, rotate, shear, scale)
// TODO implement something to dynamically change colors from input would be a cool bonus
// TODO VAO,VBO, etc. per cube is very inneficient, eventually should somehow be moved to a parent class

#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Mesh.h"
#include <string>
#include <vector>

class Cube : public Mesh {
public:
	Cube();
	~Cube();
};
