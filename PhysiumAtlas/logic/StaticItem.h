#ifndef STATIC_ITEM_H
#define STATIC_ITEM_H

#include "Hitbox.h"

class StaticItem
{
public:
	StaticItem() = delete;
	StaticItem(unsigned short textureID, Coordinates position, Coordinates size)
		: textureID(textureID), hitbox(position, size) {}
	StaticItem(unsigned short textureID, Hitbox hitbox)
		: textureID(textureID), hitbox(hitbox) {}

		Hitbox& getHitbox() { return hitbox; }

private:
	Hitbox hitbox;
	unsigned short textureID;
};

#endif
