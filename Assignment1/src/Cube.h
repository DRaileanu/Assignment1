#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Drawable.h"
#include <string>
#include <vector>

class Cube : public Drawable {
public:
	Cube();//creates cube without colours (black)
	Cube(glm::vec3 colour);//creates cube given colour
	~Cube();

};
