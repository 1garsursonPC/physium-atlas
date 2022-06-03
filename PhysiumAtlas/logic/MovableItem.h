#ifndef MOVABLE_ITEM_H
#define MOVABLE_ITEM_H

#include "StaticItem.h"

class MovableItem : public StaticItem
{
public:
	MovableItem() = delete;
	MovableItem(unsigned short textureID, Coordinates position, Coordinates size,
			Coordinates speed = {0, 0}, Coordinates acc = {0, 0});
	MovableItem(unsigned short textureID, Hitbox hitbox,
			Coordinates speed = {0, 0}, Coordinates acc = {0, 0});

	float getMass();
	void setMass(float mass);

	Coordinates& getSpeed() { return speed; }
	Coordinates& getAcceleration() { return acceleration; }

private:
	float mass;

	Coordinates speed;
	Coordinates acceleration;
}

#endif
