#pragma once
#include "logic/MovableItem.h"

class PhysicEngine
{
private:
	float g = 9.81;


public:
	PhysicEngine()
	{};
	void setG(float gravity);
	void applyWeight(MovableItem &object);

};

