#ifndef STATIC_ITEM_H
#define STATIC_ITEM_H

#include "Hitbox.h"

class StaticItem
{
public:
	StaticItem() = delete;
	StaticItem(unsigned short textureID, Coordinates upperLeft, Coordinates bottomLeft);
	StaticItem(unsigned short textureID, Hitbox hitbox);

	Hitbox& getHitbox() { return hitbox; }

private:
	Hitbox hitbox;
	unsigned short textureID;
}

#endif
