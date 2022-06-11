#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
	Coordinates() 
	:x(0), y(0) {};
	Coordinates(float x, float y)
		: x(x), y(y) {}

	float getX() { return this->x; }
	float getY() { return this->y; }

	void setCoordinates(float x, float y) { this->x = x; this->y = y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
public:
	float x;
	float y;
};

#endif
