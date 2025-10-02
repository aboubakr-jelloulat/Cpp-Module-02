#include "Point.h"

Point::Point() : x(0), y(0) {}


Point::Point(float const x, float const y) : x(x) , y(y) {}

Point::Point(Point const &other)  : x(other.get_x()), y(other.get_y()) {}


Point& Point::operator=(const Point& other)
{
	(void)other;
   
   return *this;
}

Point::~Point(){};

float Point::get_x(void) const { return this->x.toFloat(); }

float Point::get_y(void) const { return this->y.toFloat(); }
