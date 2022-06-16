#pragma once
#include "logic/MovableItem.h"

class PhysicEngine
{
private:
	float g = 0.0981;


public:
	PhysicEngine()
	{};
	void setG(float gravity);
	void applyWeight(MovableItem &object);

};

