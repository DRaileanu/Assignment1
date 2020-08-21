#pragma once
#include "Drawable.h"
#include "Particle.h"
#include "ParticleEmitter.h"
#include "Random.h"
#include <vector>


class DecorativeCubes : public Drawable {
	static const unsigned int MAX_CUBES = 5000;
	struct DecorativeCube {
		DecorativeCube() {
			int xPos = RandRange(-45, 45);
			int zPos = RandRange(-45, 45);
			position = glm::vec3(xPos, 0.0f, zPos);
			color = glm::vec3(RandUnitVec());
			keyframeProgress = 0.0f;
			keyframeDuration = 0.4f;
			keyframePos1 = position;

			switch (rand() % 4) {
			case 0:	direction = glm::vec3(1.0f, 0.0f, 0.0f);
				break;
			case 1:	direction = glm::vec3(-1.0f, 0.0f, 0.0f);
				break;
			case 2:	direction = glm::vec3(0.0f, 0.0f, 1.0f);
				break;
			case 3:	direction = glm::vec3(0.0f, 0.0f, -1.0f);
				break;
			}
			keyframePos2 = keyframePos1 + direction;
		}
        glm::vec3   position; 
		glm::vec3	direction;
		glm::vec3   color;
		glm::vec3	keyframePos1;
		glm::vec3	keyframePos2;
		float		keyframeProgress;
		float		keyframeDuration;
	};

public:
	DecorativeCubes(unsigned int numCubes = 0);
	virtual ~DecorativeCubes() {}

	void draw() override;

	virtual void Update(float dt);

	void Resize(unsigned int numCubes);


protected:
	void setupBufferData() override;
	void BuildVertexBuffer();

	std::vector<DecorativeCube>	cubes;

};

