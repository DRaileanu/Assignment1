#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Drawable.h"
#include <string>
#include <vector>

//it's just another cube class, but I needed different coordinates for a cube to texture the inside of the skybox
//probably could have done without it, but was in rush

class SkyboxCube : public Drawable {
public:
	SkyboxCube();
	~SkyboxCube();
};

