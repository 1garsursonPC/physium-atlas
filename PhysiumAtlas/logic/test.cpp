#include "test.h"

bool test_isColliding()
{
	Hitbox r1 = {{5.0, 5.0}, {10.0, 10.0}};
	Hitbox r2 = {{6.0, 6.0}, {15.0, 15.0}};

	if (r1.isColliding(r2))
		return true;
	else
		return false;
}
