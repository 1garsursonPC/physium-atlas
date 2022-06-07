#pragma once
#include "Coordinates.h"
#include "Hitbox.h"

class StaticItem {

private:
	unsigned int textureID;
	Coordinates objCoord;

public:
	StaticItem(unsigned int _txtuID, Coordinates _posHtBx, Coordinates _sizeHtBx);
	StaticItem(unsigned int _txtuID,Hitbox _objHyBx );

	Hitbox getHitBox();
};
