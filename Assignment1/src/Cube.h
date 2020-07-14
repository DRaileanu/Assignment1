#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Drawable.h"
#include <string>
#include <vector>

class Cube : public Drawable {
public:
	Cube();//creates cube with different colours on each side
	Cube(glm::vec3 colour);//creates cube with all faces of same colour given
	~Cube();

};
