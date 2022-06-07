#include "Hitbox.h"

bool Hitbox::isColliding(Hitbox hitbox)
{
	// The rectangle we are is ABCD, and the one we received
	// in arguments is FGHJ
	/*
	 * A x-----x B
	 *   |     |
	 * D x-----x C
	 *
	 * F x-----x G
	 *   |     |
	 * J x-----x H
	 */
	// WARNING : the coordinates y axis in sfml is upside down (pointing down instead of up)
	// And so are are coordinates (because we don't want to do conversion)
	Coordinates A = this->getPosition();
	Coordinates C = {this->getPosition().getX() + this->getSize().getX(),
			this->getPosition().getY() + this->getSize().getY()};

	Coordinates F = hitbox.getPosition();
	Coordinates H = {hitbox.getPosition().getX() + hitbox.getSize().getX(),
			hitbox.getPosition().getY() + hitbox.getSize().getY()};

	// Is the edge BC on the right of FJ and to the left of GH
	// Is AD on the left of GH and to the right of FJ
	// Is DC below FG and above JH
	// Is AB above JH and below FG
	if (	C.getX() >= F.getX() && C.getX() <= H.getX() ||
		A.getX() <= H.getX() && A.getX() >= F.getX() ||
		C.getY() >= F.getY() && C.getY() <= H.getY() ||
		A.getY() <= H.getY() && A.getY() >= F.getY() )
		return true;
	return false;
}
