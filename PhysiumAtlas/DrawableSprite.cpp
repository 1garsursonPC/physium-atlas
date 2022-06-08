#include "DrawableSprite.h"

void DrawableSprite::new_pos(int x, int y)
{
	sprite->setPosition(sf::Vector2f(x, y));
}