#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Drawable.h"
#include <vector>

class SceneNode {
public:
	SceneNode(Drawable* drawable = NULL);
	~SceneNode();

	const glm::mat4& getTransform() const { return localTransform; }
	void setTransform(const glm::mat4& matrix) { localTransform = matrix; }
	glm::mat4 getWorldTransform() const { return worldTransform; }

	Drawable* getDrawable() const { return drawable; }
	void setDrawable(Drawable* drawable) { this->drawable = drawable; }

	void addChild(SceneNode*);

	virtual void update(float dt);
	virtual void draw();
	
	//std::vector<SceneNode*>::const_iterator getChildIteratorStart() { return children.begin(); }
	//std::vector<SceneNode*>::const_iterator getChildIteratorEnd() { return children.end(); }
	std::vector<SceneNode*> getChildren() { return children; }
protected:
	SceneNode*	parent;
	Drawable*	drawable;
	glm::mat4	worldTransform;
	glm::mat4	localTransform;
	std::vector<SceneNode*> children;

};

