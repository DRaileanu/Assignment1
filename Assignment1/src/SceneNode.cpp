#include "SceneNode.h"

SceneNode::SceneNode() {
	localTransform = glm::mat4(1.0f);
	translation = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scaling = glm::vec3(1.0f, 1.0f, 1.0f);
	manualTransform = glm::mat4(1.0f);
	dirty = true;
}

SceneNode::~SceneNode() {}


// computes local transform using transformaiton parameters in order shear->->scale->rotate(ZYX)->translate
void SceneNode::updateLocalTransform() {
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, translation);
	transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	transform = glm::scale(transform, scaling);
	transform = transform * manualTransform;
	localTransform = transform;

}

// recursively update scene node's world transform relative to parent's
void SceneNode::updateWorldTransform(const glm::mat4& CTM) {
	if (dirty) {//replace dirty with true to see FPS difference
		updateLocalTransform();
		dirty = false;
	}
	worldTransform = CTM * localTransform;
}


void SceneNode::setTranslation(glm::vec3 t) {
	dirty = true;
	translation = t;
}

void SceneNode::setRotation(glm::vec3 r) {
	dirty = true;
	rotation = r;
}

void SceneNode::setScaling(glm::vec3 s) {
	dirty = true;
	scaling = s;
}

void SceneNode::setManualTransform(glm::mat4 m) {
	dirty = true;
	manualTransform = m;
}


void SceneNode::translate(glm::vec3 t) {
	dirty = true;
	translation += t;
}

void SceneNode::scale(glm::vec3 s) {
	dirty = true;
	scaling = s*scaling;
}

void SceneNode::rotate(glm::vec3 r) {
	dirty = true;
	rotation += r;
}
void SceneNode::moveForward(float amount) {
	dirty = true;
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -amount));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	translation += glm::vec3((rot * trans)[3]);
}
void SceneNode::moveBackwards(float amount) {
	dirty = true;
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, amount));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	translation += glm::vec3((rot * trans)[3]);
}

void SceneNode::strafeLeft(float amount) {
	dirty = true;
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(-amount, 0.0f, 0.0f));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	translation += glm::vec3((rot * trans)[3]);

}

void SceneNode::strafeRight(float amount) {
	dirty = true;
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(amount, 0.0f, 0.0f));
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	translation += glm::vec3((rot * trans)[3]);

}

