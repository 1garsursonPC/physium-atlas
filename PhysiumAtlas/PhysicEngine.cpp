#include "PhysicEngine.h"
#include <iostream>

void PhysicEngine::applyWeight(MovableItem &object)
{
	object.setAcceleration(Coordinates(object.getAcceleration().getX(), g/100));
	if(object.getSpeed().getY() <= 1)
		object.setSpeed(Coordinates(object.getSpeed().getX(), object.getSpeed().getY() + object.getAcceleration().getY()));
	object.getHitbox().setPosition(Coordinates(object.getHitbox().getPosition().getX(), (object.getHitbox().getPosition().getY()) + object.getSpeed().getY()));
	//std::cout << "Vitesse : " << (object.getSpeed().getY()) << std::endl;
	//std::cout << "Acc : " << object.getAcceleration().getY() << std::endl;
	//std::cout << "Vitesse : " << (object.getHitbox().getPosition().getY()) + object.getSpeed().getY() << std::endl;

}