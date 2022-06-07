#ifndef HITBOX_H
#define HITBOX_H

#include "Coordinates.h"

class Hitbox
{
public:
	Hitbox() = delete;
	Hitbox(Coordinates position, Coordinates size)
		: position(position), size(size) {}

	bool isColliding(const Hitbox hitbox);

	Coordinates& getPosition() { return this->position; }
	Coordinates& getSize() { return this->size; }

private:
	Coordinates position;
	Coordinates size;
};

#endif
