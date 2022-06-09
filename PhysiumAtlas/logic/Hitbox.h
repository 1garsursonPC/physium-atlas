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
	void setPosition(Coordinates _nwpos) { position = _nwpos; }
	void setSize(Coordinates _nwsize) { size = _nwsize; }

private:
	Coordinates position;
	Coordinates size;
};

#endif
