#include "ParticleEmitter.h"
#include "Random.h"


ParticleEmitter::ParticleEmitter() :
	MinWidth(-1),
	MaxWidth(-1),
	MinHeight(-1),
	MaxHeight(-1),
	MinDepth(-1),
	MaxDepth(-1),
	MinSpeed(10),
	MaxSpeed(20),
	MinLifetime(3),
	MaxLifetime(5),
	Origin(0)
{}

void ParticleEmitter::EmitParticle(Particle& particle) {
	float x = RandRange(MinWidth, MaxWidth);
	float y = RandRange(MinHeight, MaxHeight);
	float z = RandRange(MinDepth, MaxDepth);

	float lifetime = RandRange(MinLifetime, MaxLifetime);
	float speed = RandRange(MinSpeed, MaxSpeed);

	glm::vec3 vector(x, y, z);

	particle.m_Position = vector + Origin;
	particle.m_Velocity = glm::normalize(vector) * speed;

	particle.m_fLifeTime = lifetime;
	particle.m_fAge = 0;
}