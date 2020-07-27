#pragma once
#include "SceneNode.h"
#include "Drawable.h"

struct Material {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
};

class DrawNode : public SceneNode {
public:
	//DrawNode() {}
	DrawNode(Drawable* d) : drawable(d), transparency(0) {}
	~DrawNode() {}

	Drawable* getDrawable() { return drawable; }
	void setDrawable(Drawable* d) { drawable = d; }

	void draw() {
		if (drawable) {
			drawable->draw();
		}
	}

	Material* getMaterial() { return material; }
	void setMaterial(Material* m) { material = m; }

	GLuint getTexture() { return texture; }
	void setTexture(GLuint tex) { texture = tex; }

	float getTransparency() { return transparency; }
	void setTransparency(float t) { transparency = t; }

private:
	Drawable* drawable;
	Material* material;
	GLuint texture;
	float transparency;
};

