#include "Player.h"
#include <iostream>

Player::Player(unsigned short _textureID, Coordinates _position, Coordinates _size, float _mass,
	Coordinates speed , Coordinates acc)
	:MovableItem(_textureID, _position, _size, _mass, speed, acc)
{
}

void Player::jump(float elapsedtime)
{
	setAcceleration(Coordinates(getAcceleration().getX(), -0.5));
	if (getSpeed().getY() <= 1.5)
		setSpeed(Coordinates(getSpeed().getX(), getSpeed().getY() + getAcceleration().getY()));
	getHitbox().setPosition(Coordinates(getHitbox().getPosition().getX(), (getHitbox().getPosition().getY()) + getSpeed().getY()));

}

void Player::moveRight(float elapsedtime)
{
	setAcceleration( Coordinates(1.2,getAcceleration().getY() ) );
	if (getSpeed().getX() <= 0.3) {
		setSpeed( Coordinates(getSpeed().getX() + getAcceleration().getX() * elapsedtime, getSpeed().getY() + getAcceleration().getY() * elapsedtime) );
	}
	getHitbox().setPosition(Coordinates( (getHitbox().getPosition().getX()) + (getSpeed().getX() * 1) , getHitbox().getPosition().getY()));
}

void Player::moveLeft(float elapsedtime)
{
	setAcceleration(Coordinates(-1.2, getAcceleration().getY()));
	if (getSpeed().getX() >= -0.3) {
		setSpeed(Coordinates(getSpeed().getX() + getAcceleration().getX() * elapsedtime, getSpeed().getY() + getAcceleration().getX() * elapsedtime));
	}
	getHitbox().setPosition(Coordinates((getHitbox().getPosition().getX()) + (getSpeed().getX() * 1), getHitbox().getPosition().getY()));
}

void Player::idle(float elapsedtime)
{
	if (getSpeed().getX() > 0 && getAcceleration().getX() > 0)
	{
		setSpeed(Coordinates(getSpeed().getX() - getAcceleration().getX() * elapsedtime / 0.5, getSpeed().getY()));
	}	
	else if (getSpeed().getX() < 0 && getAcceleration().getX() < 0) {
		setSpeed(Coordinates(getSpeed().getX() - getAcceleration().getX() * elapsedtime / 0.5, getSpeed().getY()));
	}
	else if (getSpeed().getY() > 0)
	{
		setSpeed(Coordinates(getSpeed().getX(), getSpeed().getY() - getAcceleration().getY() * elapsedtime / 0.5));
	}
	else
	{
		setSpeed(Coordinates(0, 0));
		setAcceleration(Coordinates(0, 0));
	}
	getHitbox().setPosition(Coordinates((getHitbox().getPosition().getX()) + (getSpeed().getX() * 1), (getHitbox().getPosition().getY())));

}
