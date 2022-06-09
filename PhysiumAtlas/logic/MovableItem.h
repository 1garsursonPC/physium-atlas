#ifndef MOVABLE_ITEM_H
#define MOVABLE_ITEM_H

#include "StaticItem.h"

class MovableItem : public StaticItem
{
public:
	MovableItem() = delete;
	MovableItem(unsigned short _textureID, Coordinates _position, Coordinates _size, float _mass,
		Coordinates speed = { 0, 0 }, Coordinates acc = { 0, 0 }) 
		:StaticItem(_textureID,_position,_size), mass(_mass) {}
	MovableItem(unsigned short textureID, Hitbox hitbox, float _mass,
		Coordinates speed = { 0, 0 }, Coordinates acc = { 0, 0 }) 
		:StaticItem(textureID,hitbox), mass(_mass) {}

	float getMass();
	void setMass(float mass);

	Coordinates& getSpeed() { return speed; }
	Coordinates& getAcceleration() { return acceleration; }
	void setSpeed(Coordinates _nwSpeed) { speed = _nwSpeed; }
	void setAcceleration(Coordinates _nwAcc) { acceleration = _nwAcc; }

private:
	float mass;

	Coordinates speed;
	Coordinates acceleration;
};

#endif
