#pragma once
class Coordinates
{

private:
	float x;
	float y;

public:
	Coordinates(float _x,float _y);
	
	float getX();
	float getY();
	
	void setCoordinates(float _x, float _y);
	void setX(float _x); 
	void setY(float _y);
};

