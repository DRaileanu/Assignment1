#include "RubikCube.h"

RubikCube::RubikCube() {
	animated = false;
	animationDuration = 0.25f;
	//setup all the rubikParts
	GroupNode* rubikPart;

	//1,1,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, -1.0f, 1.0f));
	rubikParts[std::make_tuple(1, 1, 1)] = rubikPart;
	addChild(rubikPart);
	//1,1,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, -1.0f, 0.0f));
	rubikParts[std::make_tuple(1, 1, 2)] = rubikPart;
	addChild(rubikPart);
	//1,1,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, -1.0f, -1.0f));
	rubikParts[std::make_tuple(1, 1, 3)] = rubikPart;
	addChild(rubikPart);
	//1,2,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 0.0f, 1.0f));
	rubikParts[std::make_tuple(1, 2, 1)] = rubikPart;
	addChild(rubikPart);
	//1,2,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
	rubikParts[std::make_tuple(1, 2, 2)] = rubikPart;
	addChild(rubikPart);
	//1,2,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 0.0f, -1.0f));
	rubikParts[std::make_tuple(1, 2, 3)] = rubikPart;
	addChild(rubikPart);
	//1,3,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 1.0f, 1.0f));
	rubikParts[std::make_tuple(1, 3, 1)] = rubikPart;
	addChild(rubikPart);
	//1,3,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 1.0f, 0.0f));
	rubikParts[std::make_tuple(1, 3, 2)] = rubikPart;
	addChild(rubikPart);
	//1,3,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(-1.0f, 1.0f, -1.0f));
	rubikParts[std::make_tuple(1, 3, 3)] = rubikPart;
	addChild(rubikPart);
	//2,1,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, -1.0f, 1.0f));
	rubikParts[std::make_tuple(2, 1, 1)] = rubikPart;
	addChild(rubikPart);
	//2,1,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, -1.0f, 0.0f));
	rubikParts[std::make_tuple(2, 1, 2)] = rubikPart;
	addChild(rubikPart);
	//2,1,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, -1.0f, -1.0f));
	rubikParts[std::make_tuple(2, 1, 3)] = rubikPart;
	addChild(rubikPart);
	//2,2,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 0.0f, 1.0f));
	rubikParts[std::make_tuple(2, 2, 1)] = rubikPart;
	addChild(rubikPart);
	//2,2,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 0.0f, 0.0f));
	rubikParts[std::make_tuple(2, 2, 2)] = rubikPart;
	addChild(rubikPart);
	//2,2,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 0.0f, -1.0f));
	rubikParts[std::make_tuple(2, 2, 3)] = rubikPart;
	addChild(rubikPart);
	//2,3,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 1.0f, 1.0f));
	rubikParts[std::make_tuple(2, 3, 1)] = rubikPart;
	addChild(rubikPart);
	//2,3,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 1.0f, 0.0f));
	rubikParts[std::make_tuple(2, 3, 2)] = rubikPart;
	addChild(rubikPart);
	//2,3,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(0.0f, 1.0f, -1.0f));
	rubikParts[std::make_tuple(2, 3, 3)] = rubikPart;
	addChild(rubikPart);
	//3,1,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, -1.0f, 1.0f));
	rubikParts[std::make_tuple(3, 1, 1)] = rubikPart;
	addChild(rubikPart);
	//3,1,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, -1.0f, 0.0f));
	rubikParts[std::make_tuple(3, 1, 2)] = rubikPart;
	addChild(rubikPart);
	//3,1,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, -1.0f, -1.0f));
	rubikParts[std::make_tuple(3, 1, 3)] = rubikPart;
	addChild(rubikPart);
	//3,2,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 0.0f, 1.0f));
	rubikParts[std::make_tuple(3, 2, 1)] = rubikPart;
	addChild(rubikPart);
	//3,2,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 0.0f, 0.0f));
	rubikParts[std::make_tuple(3, 2, 2)] = rubikPart;
	addChild(rubikPart);
	//3,2,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 0.0f, -1.0f));
	rubikParts[std::make_tuple(3, 2, 3)] = rubikPart;
	addChild(rubikPart);
	//3,3,1
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 1.0f, 1.0f));
	rubikParts[std::make_tuple(3, 3, 1)] = rubikPart;
	addChild(rubikPart);
	//3,3,2
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 1.0f, 0.0f));
	rubikParts[std::make_tuple(3, 3, 2)] = rubikPart;
	addChild(rubikPart);
	//3,3,3
	rubikPart = new GroupNode;
	rubikPart->translate(glm::vec3(1.0f, 1.0f, -1.0f));
	rubikParts[std::make_tuple(3, 3, 3)] = rubikPart;
	addChild(rubikPart);


	//setup the DrawNodes and Quads for all rubikParts
	//all Quads facing towards +z, coordinates (x,y,1)
	for (int x = 1; x <= 3; ++x) {
		for (int y = 1; y <= 3; ++y) {
			rubikPart = rubikParts[std::make_tuple(x, y, 1)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(1.0f, 0.0f, 0.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->translate(glm::vec3(0.0f, 0.0f, 0.5f));
			rubikPart->addChild(quadNode);
		}
	}
	//all Quads facing towards -z, coordinates (x,y,3)
	for (int x = 1; x <= 3; ++x) {
		for (int y = 1; y <= 3; ++y) {
			rubikPart = rubikParts[std::make_tuple(x, y, 3)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(1.0f, 1.0f, 0.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->rotate(glm::vec3(0.0f, 180.0f, 0.0f));
			quadNode->translate(glm::vec3(0.0f, 0.0f, -0.5f));
			rubikPart->addChild(quadNode);
		}
	}
	//all Quads facing towards +x, coordinates (3,y,z)
	for (int y = 1; y <= 3; ++y) {
		for (int z = 1; z <= 3; ++z) {
			rubikPart = rubikParts[std::make_tuple(3, y, z)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(1.0f, 0.0f, 1.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->rotate(glm::vec3(0.0f, 90.0f, 0.0f));
			quadNode->translate(glm::vec3(0.5f, 0.0f, 0.0f));
			rubikPart->addChild(quadNode);
		}
	}
	//all Quads facing towards -x, coordinates (1,y,z)
	for (int y = 1; y <= 3; ++y) {
		for (int z = 1; z <= 3; ++z) {
			rubikPart = rubikParts[std::make_tuple(1, y, z)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(0.0f, 1.0f, 0.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->rotate(glm::vec3(0.0f, -90.0f, 0.0f));
			quadNode->translate(glm::vec3(-0.5f, 0.0f, 0.0f));
			rubikPart->addChild(quadNode);
		}
	}
	//all Quads facing towards +y, coordinates (x,3,z)
	for (int x = 1; x <= 3; ++x) {
		for (int z = 1; z <= 3; ++z) {
			rubikPart = rubikParts[std::make_tuple(x, 3, z)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(0.0f, 1.0f, 1.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->rotate(glm::vec3(-90.0f, 0.0f, 0.0f));
			quadNode->translate(glm::vec3(0.0f, 0.5f, 0.0f));
			rubikPart->addChild(quadNode);
		}
	}
	//all Quads facing towards -y, coordinates (x,1,z)
	for (int x = 1; x <= 3; ++x) {
		for (int z = 1; z <= 3; ++z) {
			rubikPart = rubikParts[std::make_tuple(x, 1, z)];
			Drawable* quad = new Quad;
			quad->setColours(glm::vec3(0.0f, 0.0f, 1.0f));
			DrawNode* quadNode = new DrawNode(quad);
			quadNode->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
			quadNode->translate(glm::vec3(0.0f, -0.5f, 0.0f));
			rubikPart->addChild(quadNode);
		}
	}


}



void RubikCube::updateWorldTransform(const glm::mat4& CTM) {
	if (animated) {
		animationUpdate();
	}
	SceneNode::updateWorldTransform(CTM);
}

void RubikCube::animationUpdate() {
	static bool animationInProgress = false;
	static float animationStartFrame = glfwGetTime();
	static float lastFrame = glfwGetTime();
	
	if (!animationInProgress) {
		animationInProgress = true;
		lastFrame = animationStartFrame = glfwGetTime();
	}
	else {
		float currentFrame = glfwGetTime();
		float dt;

		if (animationStartFrame + animationDuration <= currentFrame) {
			dt = animationStartFrame + animationDuration - lastFrame;
			animationInProgress = false;
			animated = false;
		}
		else {
			dt = currentFrame - lastFrame;
		}
		lastFrame = currentFrame;


		glm::vec3 deltaRotation = (dt / animationDuration) * animationRotation;
		glm::quat rotationQuaternion(glm::radians(deltaRotation));
		glm::mat4 rotationMatrix = glm::mat4_cast(rotationQuaternion);
		for (auto& animNode : animationNodes) {
			animNode->rotate(rotationMatrix);
			glm::vec3 translation = animNode->getTranslation();
			glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation);
			glm::mat4 rotatedTranslationMatrix = rotationMatrix * translationMatrix;
			glm::vec3 rotatedTranslation = glm::vec3(rotatedTranslationMatrix[3]);
			animNode->setTranslation(rotatedTranslation);

		}
		
		
	}
	
	//for testing by performing rotation 1 in frame
	/*
	glm::vec3 deltaRotation = animationRotation;
	glm::quat rotationQuaternion(glm::radians(deltaRotation));
	glm::mat4 rotationMatrix = glm::mat4_cast(rotationQuaternion);
	for (auto& animNode : animationNodes) {
		animNode->rotate(rotationMatrix);

		glm::vec3 translation = animNode->getTranslation();
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation);
		glm::mat4 rotatedTranslationMatrix = rotationMatrix * translationMatrix;
		glm::vec3 rotatedTranslation = glm::vec3(rotatedTranslationMatrix[3]);
		animNode->setTranslation(rotatedTranslation);

	}
	animated = false;
	*/

}

void RubikCube::rotatePositiveXCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int y = 1; y <= 3; ++y) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int,int,int> coord(3, y, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(-90.0f, 0.0f, 0.0f);

		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(3, 1, 3)];
		rubikParts.at(std::make_tuple(3, 1, 2)) = temp[std::make_tuple(3, 2, 3)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(3, 2, 1)) = temp[std::make_tuple(3, 1, 2)];
		rubikParts.at(std::make_tuple(3, 2, 3)) = temp[std::make_tuple(3, 3, 2)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(3, 1, 1)];
		rubikParts.at(std::make_tuple(3, 3, 2)) = temp[std::make_tuple(3, 2, 1)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(3, 3, 1)];

	}

}

void RubikCube::rotatePositiveXCCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int y = 1; y <= 3; ++y) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(3, y, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(90.0f, 0.0f, 0.0f);

		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(3, 3, 1)];
		rubikParts.at(std::make_tuple(3, 1, 2)) = temp[std::make_tuple(3, 2, 1)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(3, 1, 1)];
		rubikParts.at(std::make_tuple(3, 2, 1)) = temp[std::make_tuple(3, 3, 2)];
		rubikParts.at(std::make_tuple(3, 2, 3)) = temp[std::make_tuple(3, 1, 2)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(3, 3, 2)) = temp[std::make_tuple(3, 2, 3)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(3, 1, 3)];

	}
}

void RubikCube::rotateNegativeXCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int y = 1; y <= 3; ++y) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(1, y, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(90.0f, 0.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(1, 3, 1)];
		rubikParts.at(std::make_tuple(1, 1, 2)) = temp[std::make_tuple(1, 2, 1)];
		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(1, 2, 1)) = temp[std::make_tuple(1, 3, 2)];
		rubikParts.at(std::make_tuple(1, 2, 3)) = temp[std::make_tuple(1, 1, 2)];
		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(1, 3, 3)];
		rubikParts.at(std::make_tuple(1, 3, 2)) = temp[std::make_tuple(1, 2, 3)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(1, 1, 3)];

	}
}

void RubikCube::rotateNegativeXCCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int y = 1; y <= 3; ++y) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(1, y, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(-90.0f, 0.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(1, 1, 3)];
		rubikParts.at(std::make_tuple(1, 1, 2)) = temp[std::make_tuple(1, 2, 3)];
		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(1, 3, 3)];
		rubikParts.at(std::make_tuple(1, 2, 1)) = temp[std::make_tuple(1, 1, 2)];
		rubikParts.at(std::make_tuple(1, 2, 3)) = temp[std::make_tuple(1, 3, 2)];
		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(1, 3, 2)) = temp[std::make_tuple(1, 2, 1)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(1, 3, 1)];

	}
}

void RubikCube::rotatePositiveYCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(x, 3, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, -90.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(3, 3, 1)];
		rubikParts.at(std::make_tuple(1, 3, 2)) = temp[std::make_tuple(2, 3, 1)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(1, 3, 1)];
		rubikParts.at(std::make_tuple(2, 3, 1)) = temp[std::make_tuple(3, 3, 2)];
		rubikParts.at(std::make_tuple(2, 3, 3)) = temp[std::make_tuple(1, 3, 2)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(3, 3, 2)) = temp[std::make_tuple(2, 3, 3)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(1, 3, 3)];

	}
}

void RubikCube::rotatePositiveYCCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(x, 3, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 90.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(1, 3, 3)];
		rubikParts.at(std::make_tuple(1, 3, 2)) = temp[std::make_tuple(2, 3, 3)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(2, 3, 1)) = temp[std::make_tuple(1, 3, 2)];
		rubikParts.at(std::make_tuple(2, 3, 3)) = temp[std::make_tuple(3, 3, 2)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(1, 3, 1)];
		rubikParts.at(std::make_tuple(3, 3, 2)) = temp[std::make_tuple(2, 3, 1)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(3, 3, 1)];

	}
}

void RubikCube::rotateNegativeYCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(x, 1, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 90.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(1, 1, 3)];
		rubikParts.at(std::make_tuple(1, 1, 2)) = temp[std::make_tuple(2, 1, 3)];
		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(3, 1, 3)];
		rubikParts.at(std::make_tuple(2, 1, 1)) = temp[std::make_tuple(1, 1, 2)];
		rubikParts.at(std::make_tuple(2, 1, 3)) = temp[std::make_tuple(3, 1, 2)];
		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(3, 1, 2)) = temp[std::make_tuple(2, 1, 1)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(3, 1, 1)];

	}
}

void RubikCube::rotateNegativeYCCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int z = 1; z <= 3; ++z) {
				std::tuple<int, int, int> coord(x, 1, z);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, -90.0f, 0.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(3, 1, 1)];
		rubikParts.at(std::make_tuple(1, 1, 2)) = temp[std::make_tuple(2, 1, 1)];
		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(2, 1, 1)) = temp[std::make_tuple(3, 1, 2)];
		rubikParts.at(std::make_tuple(2, 1, 3)) = temp[std::make_tuple(1, 1, 2)];
		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(3, 1, 3)];
		rubikParts.at(std::make_tuple(3, 1, 2)) = temp[std::make_tuple(2, 1, 3)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(1, 1, 3)];

	}
}

void RubikCube::rotatePositiveZCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int y = 1; y <= 3; ++y) {
				std::tuple<int, int, int> coord(x, y, 1);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 0.0f, -90.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(3, 1, 1)];
		rubikParts.at(std::make_tuple(2, 1, 1)) = temp[std::make_tuple(3, 2, 1)];
		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(3, 3, 1)];
		rubikParts.at(std::make_tuple(1, 2, 1)) = temp[std::make_tuple(2, 1, 1)];
		rubikParts.at(std::make_tuple(3, 2, 1)) = temp[std::make_tuple(2, 3, 1)];
		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(2, 3, 1)) = temp[std::make_tuple(1, 2, 1)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(1, 3, 1)];

	}
}

void RubikCube::rotatePositiveZCCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int y = 1; y <= 3; ++y) {
				std::tuple<int, int, int> coord(x, y, 1);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 0.0f, 90.0f);

		rubikParts.at(std::make_tuple(1, 1, 1)) = temp[std::make_tuple(1, 3, 1)];
		rubikParts.at(std::make_tuple(2, 1, 1)) = temp[std::make_tuple(1, 2, 1)];
		rubikParts.at(std::make_tuple(3, 1, 1)) = temp[std::make_tuple(1, 1, 1)];
		rubikParts.at(std::make_tuple(1, 2, 1)) = temp[std::make_tuple(2, 3, 1)];
		rubikParts.at(std::make_tuple(3, 2, 1)) = temp[std::make_tuple(2, 1, 1)];
		rubikParts.at(std::make_tuple(1, 3, 1)) = temp[std::make_tuple(3, 3, 1)];
		rubikParts.at(std::make_tuple(2, 3, 1)) = temp[std::make_tuple(3, 2, 1)];
		rubikParts.at(std::make_tuple(3, 3, 1)) = temp[std::make_tuple(3, 1, 1)];

	}
}

void RubikCube::rotateNegativeZCW() {
	if (!animated) {
		animated = true;
		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int y = 1; y <= 3; ++y) {
				std::tuple<int, int, int> coord(x, y, 3);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 0.0f, 90.0f);

		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(1, 3, 3)];
		rubikParts.at(std::make_tuple(2, 1, 3)) = temp[std::make_tuple(1, 2, 3)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(1, 1, 3)];
		rubikParts.at(std::make_tuple(1, 2, 3)) = temp[std::make_tuple(2, 3, 3)];
		rubikParts.at(std::make_tuple(3, 2, 3)) = temp[std::make_tuple(2, 1, 3)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(2, 3, 3)) = temp[std::make_tuple(3, 2, 3)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(3, 1, 3)];

	}
}

void RubikCube::rotateNegativeZCCW() {
	if (!animated) {
		animated = true;
 		animationStartTime = glfwGetTime();

		animationNodes.clear();
		std::map<std::tuple<int, int, int>, GroupNode*> temp;
		for (int x = 1; x <= 3; ++x) {
			for (int y = 1; y <= 3; ++y) {
				std::tuple<int, int, int> coord(x, y, 3);
				GroupNode* node = rubikParts[coord];
				animationNodes.push_back(node);
				temp[coord] = node;
			}
		}
		animationRotation = glm::vec3(0.0f, 0.0f, -90.0f);

		rubikParts.at(std::make_tuple(1, 1, 3)) = temp[std::make_tuple(3, 1, 3)];
		rubikParts.at(std::make_tuple(2, 1, 3)) = temp[std::make_tuple(3, 2, 3)];
		rubikParts.at(std::make_tuple(3, 1, 3)) = temp[std::make_tuple(3, 3, 3)];
		rubikParts.at(std::make_tuple(1, 2, 3)) = temp[std::make_tuple(2, 1, 3)];
		rubikParts.at(std::make_tuple(3, 2, 3)) = temp[std::make_tuple(2, 3, 3)];
		rubikParts.at(std::make_tuple(1, 3, 3)) = temp[std::make_tuple(1, 1, 3)];
		rubikParts.at(std::make_tuple(2, 3, 3)) = temp[std::make_tuple(1, 2, 3)];
		rubikParts.at(std::make_tuple(3, 3, 3)) = temp[std::make_tuple(1, 3, 3)];

	}
}

