#include "Player.h"
#include <iostream>

Player::Player(unsigned short _textureID, Coordinates _position, Coordinates _size, float _mass,
	Coordinates speed , Coordinates acc)
	:MovableItem(_textureID, _position, _size, _mass, speed, acc)
{
}

void Player::jump()
{

}

void Player::moveRight(float elapsedtime)
{
	setAcceleration( Coordinates(1.2,getAcceleration().getY() ) );
	if (getSpeed().getX() <= 30) {
		setSpeed( Coordinates(getSpeed().getX() + getAcceleration().getX() * elapsedtime, getSpeed().getY() ) );
	}
	getHitbox().setPosition(Coordinates( (getHitbox().getPosition().getX()) + (getSpeed().getX() * elapsedtime) , getHitbox().getPosition().getY() ));

}

void Player::moveLeft(float elapsedtime)
{
	setAcceleration(Coordinates(-1.2, getAcceleration().getY()));
	if (getSpeed().getX() >= -30) {
		setSpeed(Coordinates(getSpeed().getX() + getAcceleration().getX() * elapsedtime, getSpeed().getY()));
	}
	getHitbox().setPosition(Coordinates((getHitbox().getPosition().getX()) + (getSpeed().getX() * elapsedtime), getHitbox().getPosition().getY()));

}

void Player::idle()
{
	if (getSpeed().getX() > 0 && getAcceleration().getX() > 0) {
		setSpeed(Coordinates(getSpeed().getX() - getAcceleration().getX() * 0.1, getSpeed().getY()));
	}	
	else if (getSpeed().getX() < 0 && getAcceleration().getX() < 0) {
		setSpeed(Coordinates(getSpeed().getX() -s getAcceleration().getX() * 0.1, getSpeed().getY()));
	}
	else
	{
		setSpeed(Coordinates(0, 0));
		setAcceleration(Coordinates(0, 0));
	}
	getHitbox().setPosition(Coordinates((getHitbox().getPosition().getX()) + (getSpeed().getX() * 1), getHitbox().getPosition().getY()));

}