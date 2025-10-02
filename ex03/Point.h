#pragma once

#include "Fixed.h"



class Point
{

	Fixed const x;
	Fixed const y;

public :

	Point();
	Point(Point const &other);
	Point(float const x, float const y);
	~Point();

	Point&	operator=(Point const &src);

	float get_x(void)	const;
	float get_y(void)	const;

};
