#include "Point.h"
#include <iostream>
#include <cassert>


bool	bsp(Point const a, Point const b, Point const c, Point const point);

/*
	assert() is a debugging macro that checks if a condition is true.
		If the condition is false, the program crashes with an error message.
*/


int main(void)
{
  
	/*
			●------●------●
			(0,0)  P   	   (1,0)
			A & B (0.5,0)  C


			= (0.5 - 0) * (0 - 0) - (0 - 0) * (0 - 0)
			= 0.5 * 0 - 0 * 0
			= 0 → P is EXACTLY on the line
	*/

	assert(bsp(Point(0, 0), Point(0, 0), Point(1, 0), Point(0.5, 0)) == false);

	/* All at (0, 0) */

	assert(bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) == false);

	/* 


	        B (0,1)
	        |\
	        | \
	        |D \      ← D is at (0.1, 0.1) - INSIDE the triangle
	        |   \
	        |    \
	        A------C
	      (0,0)  (1,0)

	
	d1 = sign(D, A, B)  // AB
	   = sign((0.1, 0.1), (0, 0), (0, 1))
	   = (0.1 - 0) * (0 - 1) - (0 - 0) * (0.1 - 1)
	   = (0.1) * (-1) - (0) * (-0.9)
	   = -0.1 - 0
	   = -0.1  NEGATIVE
	
	d2 = sign(D, B, C)  //  BC
	   = sign((0.1, 0.1), (0, 1), (1, 0))
	   = (0.1 - 1) * (1 - 0) - (0 - 1) * (0.1 - 0)
	   = (-0.9) * (1) - (-1) * (0.1)
	   = -0.9 + 0.1
	   = -0.8  NEGATIVE
	
	d3 = sign(D, C, A)  //  CA
	   = sign((0.1, 0.1), (1, 0), (0, 0))
	   = (0.1 - 0) * (0 - 0) - (1 - 0) * (0.1 - 0)
	   = (0.1) * (0) - (1) * (0.1)
	   = 0 - 0.1
	   = -0.1   NEGATIVE
	
	
	d1 = -0.1  (negative)
	d2 = -0.8  (negative)
	d3 = -0.1  (negative)
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0)
	        = true || true || true
	        = TRUE
	
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0)
	        = false || false || false
	        = FALSE
	
	return !(has_neg && has_pos)   // && BOTH must be true
	     = !(true && false)
	     = !(false)
	     = TRUE 

	

*/



c






/* 
	Test Point OUTSIDE Triangle


	        B (0,1) -------- D (1,1) ← D is OUTSIDE 
	        |\              /
	        | \            /
	        |  \          /
	        |   \        /
	        |    \      /
	        A------C
	      (0,0)  (1,0)

	
	d1 = sign(D, A, B)  // AB
	   = sign((1, 1), (0, 0), (0, 1))
	   = (1 - 0) * (0 - 1) - (0 - 0) * (1 - 1)
	   = (1) * (-1) - (0) * (0)
	   = -1 - 0
	   = -1  NEGATIVE
	
	d2 = sign(D, B, C)  // BC
	   = sign((1, 1), (0, 1), (1, 0))
	   = (1 - 1) * (1 - 0) - (0 - 1) * (1 - 0)
	   = (0) * (1) - (-1) * (1)
	   = 0 + 1
	   = 1  POSITIVE 
	
	d3 = sign(D, C, A)  // CA
	   = sign((1, 1), (1, 0), (0, 0))
	   = (1 - 0) * (0 - 0) - (1 - 0) * (1 - 0)
	   = (1) * (0) - (1) * (1)
	   = 0 - 1
	   = -1  NEGATIVE
	
	
	d1 = -1  (negative)
	d2 =  1  (POSITIVE) 
	d3 = -1  (negative)
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0)
	        = true || false || true
	        = TRUE
	
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0)
	        = false || true || false
	        = TRUE
	
	return !(has_neg && has_pos)
	     = !(true && true)
	     = !(true)
	     = FALSE  

	→ Point OUTSIDE 

	*/

	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)) == false);



	/* 
	B
	|\
	| \
	|  \
	A---C
	  D
	*/
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, -0.1)) == false);


	/* 
	B
	|\
	| \
	|  \
	A-D-C
	*/

	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, 0)) == false);


	/* Counterclockwise, inside
	C
	|\
	| \
	|D \
	A---B
	*/
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.1, 0.1)) == true);




	Point p1(42.2, 19.5);
	Point p2(13.3, 19.5);
	p1 = p2;


	std::cout << "\nCongrats " << std::endl;

	return 0;
}
