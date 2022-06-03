#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
	Coordinates() = delete;
	Coordinates(float x, float y);

	float getX();
	float getY();

	void setCoordinates(float x, float y);
	void setX(float x);
	void setY(float y);
public:
	float x;
	float y;
}

#endif
