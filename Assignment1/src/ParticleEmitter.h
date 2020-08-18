#pragma once;

#include "Particle.h"

class ParticleEmitter {
public:
    ParticleEmitter();
    virtual ~ParticleEmitter() {}

    virtual void EmitParticle(Particle& particle);

    float MinWidth;
    float MaxWidth;

    float MinHeight;
    float MaxHeight;

    float MinDepth;
    float MaxDepth;

    float MinSpeed;
    float MaxSpeed;

    float MinLifetime;
    float MaxLifetime;

    glm::vec3   Origin;
};