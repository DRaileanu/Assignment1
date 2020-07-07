#pragma once
#include "SceneNode.h"
#include <vector>

class Grid : public SceneNode {
public:
	Grid();
	~Grid();

private:
	void createGrid();
};

