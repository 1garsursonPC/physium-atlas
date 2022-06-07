#pragma once
#include "Coordinates.h"

class Hitbox
{
private:
	Coordinates size;
	Coordinates position;

public:
	Hitbox(Coordinates _posHtBX, Coordinates _sizeHtBx);
	bool isColliding(Hitbox _hitbox);

};

