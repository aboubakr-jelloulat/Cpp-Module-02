#pragma once


#include <iostream>

class Fixed
{

	int	_raw;
	static const int _fractionalBits = 8;

public :

	Fixed();

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	Fixed(int const i);

	Fixed(float const f);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& out, Fixed const &f);
