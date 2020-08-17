#pragma once
#include "src/GroupNode.h"
#include "src/DrawNode.h"
#include "src/Model.h"

class Timer: public GroupNode
{
public:
	Timer();
	~Timer() {};
	Model* leftMinute;
};

