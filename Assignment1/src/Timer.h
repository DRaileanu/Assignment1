#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;



#include "GroupNode.h"
#include "DrawNode.h"
#include "Model.h"
#include <time.h>


class Timer : public GroupNode
{
private:
	unsigned long begTime = 0;
public:
	void gameStart();
	void start() {
		begTime = clock();
	}
	unsigned long elapsedTime() {
		return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
	};
	bool isTimeout(unsigned long seconds) {
		return seconds >= elapsedTime();
	};

	Timer();
	~Timer() {};
	Model* column;
	Model* leftMinute;
	Model* rightMinute;
	Model* leftSecond;
	Model* rightSecond;

};