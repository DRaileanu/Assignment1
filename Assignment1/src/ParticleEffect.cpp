#include "ParticleEmitter.h"
#include "Camera.h"
#include "Random.h"
#include "ParticleEffect.h"
#include <algorithm>


#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/matrix_operation.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

ParticleEffect::ParticleEffect(unsigned int numParticles)
    : m_pCamera(NULL)
    , m_pParticleEmitter(NULL)
    , m_LocalToWorldMatrix(1)
    //, m_Force(0, -9.81f, 0)
{
    Resize(numParticles);
    setupBufferData();
}

ParticleEffect::~ParticleEffect() {}

void ParticleEffect::SetCamera(Camera* pCamera)
{
    m_pCamera = pCamera;
}

void ParticleEffect::SetParticleEmitter(ParticleEmitter* pEmitter)
{
    m_pParticleEmitter = pEmitter;
}


void ParticleEffect::RandomizeParticle(Particle& particle)
{
    particle.m_fAge = 0.0f;
    particle.m_fLifeTime = RandRange(0.5, 1);

    glm::vec3 unitVec = RandUnitVec();

    particle.m_Position = unitVec * 0.25f;
    particle.m_Velocity = unitVec * RandRange(3, 7);
}

void ParticleEffect::RandomizeParticles()
{
    for (unsigned int i = 0; i < m_Particles.size(); ++i)
    {
        RandomizeParticle(m_Particles[i]);
    }
}

void ParticleEffect::EmitParticle(Particle& particle)
{
    assert(m_pParticleEmitter != NULL);
    m_pParticleEmitter->EmitParticle(particle);
}

void ParticleEffect::EmitParticles()
{
    if (m_pParticleEmitter == NULL)
    {
        RandomizeParticles();
    }
    else
    {
        for (unsigned int i = 0; i < m_Particles.size(); ++i)
        {
            EmitParticle(m_Particles[i]);
        }
    }
}

void ParticleEffect::BuildVertexBuffer()
{
    const glm::vec3 X(0.5, 0, 0);
    const glm::vec3 Y(0, 0.5, 0);
    const glm::vec3 Z(0, 0, 1.0);

    glm::quat cameraRotation;

    if (m_pCamera != NULL)
    {
        //cameraRotation = glm::quat(glm::radians(m_pCamera->GetRotation()));
        cameraRotation = glm::quat(glm::radians(glm::vec3(m_pCamera->Pitch, 90 + m_pCamera->Yaw, 0.0f)));
    }



    for (unsigned int i = 0; i < m_Particles.size(); ++i)
    {
        Particle& particle = m_Particles[i];
        glm::quat rotation = glm::angleAxis(particle.m_fRotate, Z);

        unsigned int vertexIndex = i * 6;
        // Bottom-left
        vertices[vertexIndex + 0] = particle.m_Position + (rotation * (-X - Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 0] = particle.m_Color;
        // Bottom-right
        vertices[vertexIndex + 1] = particle.m_Position + (rotation * (X - Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 1] = particle.m_Color;

        // Top-right
        vertices[vertexIndex + 2] = particle.m_Position + (rotation * (X + Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 2] = particle.m_Color;

        // Bottom-left
        vertices[vertexIndex + 3] = particle.m_Position + (rotation * (-X - Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 3] = particle.m_Color;
        
        // Top-right
        vertices[vertexIndex + 4] = particle.m_Position + (rotation * (X + Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 4] = particle.m_Color;

        // Top-left
        vertices[vertexIndex + 5] = particle.m_Position + (rotation * (-X + Y) * particle.m_fSize) * cameraRotation;
        colours[vertexIndex + 5] = particle.m_Color;
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[VERTEX_BUFFER]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec3) * vertices.size(), &vertices[0]);
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[COLOUR_BUFFER]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec3) * colours.size(), &colours[0]);
    glBindVertexArray(0);
}

void ParticleEffect::Update(float fDeltaTime)
{
    for (unsigned int i = 0; i < m_Particles.size(); ++i)
    {
        Particle& particle = m_Particles[i];

        particle.m_fAge += fDeltaTime;
        if (particle.m_fAge > particle.m_fLifeTime)
        {
            if (m_pParticleEmitter != NULL) EmitParticle(particle);
            else RandomizeParticle(particle);
        }

        float lifeRatio = glm::clamp(particle.m_fAge / particle.m_fLifeTime, 0.0f, 1.0f);
       // particle.m_Velocity += (m_Force * fDeltaTime);
        particle.m_Position += (particle.m_Velocity * fDeltaTime);
        particle.m_Color = glm::vec3(1.0f, 0.0f, 0.0f);
        particle.m_fRotate = glm::lerp<float>(0.0f, 720.0f, lifeRatio);
        particle.m_fSize = glm::lerp<float>(0.25f, 0.0f, lifeRatio);
    }

    BuildVertexBuffer();
}


/*
void ParticleEffect::Render()
{
    glDisable(GL_DEPTH_TEST);           // Disables Depth Testing
    glEnable(GL_BLEND);                 // Enable Blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Type Of Blending To Perform
    glEnable(GL_TEXTURE_2D);            // Enable textures

    glPushMatrix();
    glMultMatrixf(glm::value_ptr(m_LocalToWorldMatrix));

    glBindTexture(GL_TEXTURE_2D, m_TextureID);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &(m_VertexBuffer[0].m_Pos));
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), &(m_VertexBuffer[0].m_Diffuse));

    glDrawArrays(GL_QUADS, 0, m_VertexBuffer.size());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glBindTexture(GL_TEXTURE_2D, 0);


    glPopMatrix();

}
*/

void ParticleEffect::Resize(unsigned int numParticles)
{
    numParticles = std::min(numParticles, MAX_PARTICLES);
    m_Particles.resize(numParticles, Particle());
    vertices.resize(6 * numParticles);
    colours.resize(6 * numParticles);
}

void ParticleEffect::setupBufferData() {
    glBindVertexArray(VAO);
    //positions
    glGenBuffers(1, &bufferObjects[VERTEX_BUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[VERTEX_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * 6 * MAX_PARTICLES, NULL, GL_STATIC_DRAW);
    glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(VERTEX_BUFFER);
    
    //colours
    glGenBuffers(1, &bufferObjects[COLOUR_BUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[COLOUR_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * 6 * MAX_PARTICLES, NULL, GL_STATIC_DRAW);
    glVertexAttribPointer(COLOUR_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(COLOUR_BUFFER);
    
    glBindVertexArray(0);
}

