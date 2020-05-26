#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	// Public class variables
	double x;	// Defines x axis
	double y;	// Defines y axis
	double z;	// Defines z axis


	// class constructors
	Vector3(double x, double y)	// Defines x and y with doubles, z = 0
	{
		x = x;
		y = y;
		z = 0;
	}

	Vector3(double x, double y, double z) // defines x, y, and z with doubles
	{
		x = x;
		y = y;
		z = z;
	}

};


#endif