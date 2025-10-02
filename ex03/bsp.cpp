#include "Point.h"

// https://stackoverflow.com/a/2049593/13279557


float	sign(Point const &p1, Point const &p2, Point const &p3)
{
    return	(p1.get_x() - p3.get_x())
		*	(p2.get_y() - p3.get_y())
		-	(p2.get_x() - p3.get_x())
		*	(p1.get_y() - p3.get_y());
}

/*
	LEFT  = POSITIVE (+)
	RIGHT = NEGATIVE (-)
*/

/*
	A point is INSIDE the triangle when

	All signs are POSITIVE 

	OR

	All signs are NEGATIVE 

*/



bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3; // ab  bc ca
    bool has_neg, has_pos;

	d1 = sign(point, a, b);
	if (d1 == 0) return false;
	
    d2 = sign(point, b, c);
	if (d2 == 0) return false;
	
    d3 = sign(point, c, a);
	if (d3 == 0) return false;
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);


	return !(has_neg && has_pos);
}
