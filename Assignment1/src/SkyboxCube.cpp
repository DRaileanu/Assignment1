#include "SkyboxCube.h"


SkyboxCube::SkyboxCube() {
    vertices = {
        glm::vec3(-1.0f,  1.0f, -1.0f),
        glm::vec3(-1.0f, -1.0f, -1.0f),
        glm::vec3(1.0f, -1.0f, -1.0f),
         glm::vec3(1.0f, -1.0f, -1.0f),
        glm::vec3(1.0f,  1.0f, -1.0f),
        glm::vec3(-1.0f,  1.0f, -1.0f),

        glm::vec3(-1.0f, -1.0f,  1.0f),
       glm::vec3(-1.0f, -1.0f, -1.0f),
        glm::vec3(-1.0f,  1.0f, -1.0f),
        glm::vec3(-1.0f,  1.0f, -1.0f),
        glm::vec3(-1.0f,  1.0f,  1.0f),
        glm::vec3(-1.0f, -1.0f,  1.0f),

        glm::vec3(1.0f, -1.0f, -1.0f),
       glm::vec3(1.0f, -1.0f,  1.0f),
        glm::vec3(1.0f,  1.0f,  1.0f),
        glm::vec3(1.0f,  1.0f,  1.0f),
        glm::vec3(1.0f,  1.0f, -1.0f),
        glm::vec3(1.0f, -1.0f, -1.0f),

       glm::vec3(-1.0f, -1.0f,  1.0f),
       glm::vec3(-1.0f,  1.0f,  1.0f),
       glm::vec3(1.0f,  1.0f,  1.0f),
        glm::vec3(1.0f,  1.0f,  1.0f),
        glm::vec3(1.0f, -1.0f,  1.0f),
       glm::vec3(-1.0f, -1.0f,  1.0f),

        glm::vec3(-1.0f,  1.0f, -1.0f),
       glm::vec3(1.0f,  1.0f, -1.0f),
       glm::vec3(1.0f,  1.0f,  1.0f),
       glm::vec3(1.0f,  1.0f,  1.0f),
       glm::vec3(-1.0f,  1.0f,  1.0f),
       glm::vec3(-1.0f,  1.0f, -1.0f),

       glm::vec3(-1.0f, -1.0f, -1.0f),
       glm::vec3(-1.0f, -1.0f,  1.0f),
       glm::vec3(1.0f, -1.0f, -1.0f),
       glm::vec3(1.0f, -1.0f, -1.0f),
      glm::vec3(-1.0f, -1.0f,  1.0f),
      glm::vec3(1.0f, -1.0f,  1.0f)
    };

    setupBufferData();
}


SkyboxCube::~SkyboxCube() {};