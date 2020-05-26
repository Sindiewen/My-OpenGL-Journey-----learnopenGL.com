#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	// Public class variables
	double x;	// Defines x axis
	double y;	// Defines y axis

	Vector2(double x, double y)	// Defines x and y with doubles
	{
		x = x;
		y = y;
	}


private:
	double z = 0;	// Defines z becuase openGL is always 3d, make sure z is 0
};


#endif
