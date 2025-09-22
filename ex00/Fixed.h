#pragma once

class Fixed
{
	int	_value;
	static const int _fractional = 8;
 
public : 
	Fixed();

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};



/*
	Copy Constructor :
		What it is:
			* A special constructor that creates a new object as an exact copy of an existing object
		When it's called:
			* When you create a new object from an existing one: Fixed b(a); or Fixed b = a;
*/

/*
	Copy Assignment Operator
		What it is:
			* An operator that copies the contents of one existing object to another existing object
		When it's called:
			* When you use the = operator between two existing objects: c = b
*/


