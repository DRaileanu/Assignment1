#pragma once

#include "Drawable.h"
#include "Particle.h"
#include "ParticleEmitter.h"
#include "Camera.h"
#include <vector>
#include <string>


/**
 * ParticleEffect class that sets up, updates and renders  particles.
 * The general approach and some code was inspired from https://www.3dgep.com/simulating-particle-effects-using-opengl/#Taking_full_advantage_of_the_power_of_the_GPU
 * Although particles are normally made using billboard quads, these particles will be rotated/translated around as a 3d object, hence they are modeled as cubes.
 */

class ParticleEffect : public Drawable {
    static const unsigned int MAX_PARTICLES = 1000;
public:
    ParticleEffect(unsigned int numParticles = 0);
    virtual ~ParticleEffect();

    void SetParticleEmitter(ParticleEmitter* pEmitter);

    // Test method to randomize the particles in an interesting way
    void RandomizeParticles();
    void EmitParticles();

    virtual void Update(float fDeltaTime);

    // Resize the particle buffer with numParticles
    void Resize(unsigned int numParticles);

protected:
    void setupBufferData() override;
    void RandomizeParticle(Particle& particle);
    void EmitParticle(Particle& particle);
public:
    // Build the vertex buffer from the particle buffer
    void BuildVertexBuffer();
private:
    ParticleEmitter* m_pParticleEmitter;

    std::vector<Particle>      m_Particles;
    // Apply this force to every particle in the effect
    //glm::vec3           m_Force;
};