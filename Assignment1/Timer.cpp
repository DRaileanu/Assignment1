#include "Timer.h"

Timer::Timer() {
	leftMinute = new Model('1');
	std::cout << "created model";
	leftMinute->translate(glm::vec3(35.0f, 0.0f, -45.0f));
	addChild(leftMinute);
}