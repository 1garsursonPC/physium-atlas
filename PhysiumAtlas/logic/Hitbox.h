#ifndef HITBOX_H
#define HITBOX_H

#include "Coordinates.h"

class Hitbox
{
public:
	Hitbox() = delete;
	Hitbox(Coordinates position, Coordinates size);

	bool isColliding(Hitbox hitbox);

	Coordinates& getPosition();
	Coordinates& getSize();

private:
	Coordinates position;
	Coordinates size;
}

#endif
