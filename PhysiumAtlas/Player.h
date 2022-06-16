#pragma once
#include <string>
#include "logic/MovableItem.h"
class Player :public MovableItem
{
private:
	std::string name;

public:
	Player(unsigned short _textureID, Coordinates _position, Coordinates _size, float _mass,
		Coordinates speed = { 0, 0 }, Coordinates acc = { 0, 0 });
	void setName(std::string _name) { name = _name; };

	//Movement
	void jump();
	void moveRight(float elapsedtime);
	void moveLeft(float elapsedtime);
	void idle(float elapsedtime);


};

