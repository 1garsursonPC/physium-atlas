#include "PhysicEngine.h"
#include <iostream>

void PhysicEngine::applyWeight(MovableItem &object)
{
	object.setAcceleration(Coordinates(object.getAcceleration().getX(), -g));
	object.setSpeed(Coordinates(object.getSpeed().getX(), object.getSpeed().getY() + object.getAcceleration().getY()));
	object.getHitbox().setPosition(Coordinates(object.getHitbox().getPosition().getX(), (object.getHitbox().getPosition().getY()) + object.getSpeed().getY()));
	std::cout << "Vitesse : " << (object.getHitbox().getPosition().getY()) << std::endl;

}