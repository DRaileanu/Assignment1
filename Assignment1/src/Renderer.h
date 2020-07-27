// Renderer class that traverses SceneNode recursively to render the scene. Also manages shaders.

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Camera.h"
#include "GroupNode.h"
#include "DrawNode.h"
#include "Shader.h"
#include "LightNode.h"

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

class Renderer{
	const static int MAX_LIGHTS = 3;//be sure that it matches the MAX_LIGHTS from shaders
	const static unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;//quality of depth map
	//if want variable far_plane, need to send them to shaders in render() and not in constructor!
	const float near_plane = 0.1;//minimum distance from which depth is computed
	const float far_plane = 100;//maximum distance at which depth is computed
public:
	Renderer(Camera* camera, Shader* genericShader, Shader* lightingMaterial, Shader* lightingTexture, Shader* shadowShader);
	~Renderer();

	void updateScene();
	void render();

	void setRootSceneNode(GroupNode* node) { rootSceneNode = node; }
	void removeRootSceneNode() { rootSceneNode = NULL; }

	void setShadowCasterLight(LightNode* light) { shadowCasterLight = light; }

	//drawing parameters
	void setPolygonMode(GLuint mode) { polygonMode = mode; }
	void setTexRatio(float ratio) { texRatio = ratio; }
	void setShadowMode(bool mode) { shadowMode = mode; }

	void postRender();//for benchmarking purposes, remove later. (need to be called after every preRender/render or refilling drawables list with repeating data)

private:
	Shader* genericShader;
	Shader* lightingMaterial;
	Shader* lightingTexture;
	Shader* shadowShader;

	Camera* mainCamera;

	GroupNode* rootSceneNode;

	std::vector<DrawNode*> genericDraws;
	std::vector<DrawNode*> opaqueTexDraws;
	std::vector<DrawNode*> opaqueMaterialDraws;
	std::map< float, DrawNode*> transparentDraws;

	GLuint pointLightsUniformBlock;
	std::vector<LightNode*> lights;

	LightNode* shadowCasterLight;

	GLuint polygonMode;
	float texRatio;
	bool shadowMode;

	GLuint depthMapFBO = 0;//frame buffer for rendering shadows
	GLuint depthCubeMap = 0;//cube depth map texture to hold info for shadow maping Point Lights


	

	void updateNode(SceneNode* node, const glm::mat4& CTM);
	void renderNode(DrawNode* node, Shader*);
	void shadowRenderNode(DrawNode* node);
	

};

