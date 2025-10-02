#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.h"


Fixed::Fixed() : _raw(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_raw = other._raw;

	return *this;

}

// *** 

Fixed::Fixed(int const i) 
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = i << _fractionalBits;  // * 256 

	// std::cout << this->_raw << std::endl; // 2560
}

Fixed::Fixed(float const f) 
{
	std::cout << "Float constructor called" << std::endl;

	this->_raw = roundf(f * (1 << _fractionalBits));

	// this->_raw = roundf(f * 256);

	//std::cout << f * (1 << _fractionalBits) << std::endl;

	// std::cout << this->_raw << std::endl;


	// std::cout << (1 << _fractionalBits) << std::endl; // 256

}

// converting FROM fixed-point TO IEEE 754 floating-point.
float Fixed::toFloat(void) const 
{
	// Convert by dividing by 2^fractionalBits
    return static_cast<float>(this->_raw) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return this->_raw >> _fractionalBits;
}


// *** 

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}


Fixed::~Fixed()	{ std::cout << "Destructor called" << std::endl; }


//  overload of the << operator


std::ostream& operator<<(std::ostream& out, Fixed const &f) {return out << f.toFloat(); }


/*

	Fixed Point :
		Fixed point is a representation method (or format) for storing and displaying numbers in computers.
		In fixed point representation, you decide in advance how many digits go before and after the decimal point, and it never changes.

	Why Use Fixed-Point?

		Problem: Computers are bad at handling decimal numbers accurately with normal floats

		float a = 0.1;
		float b = 0.2;
		float c = a + b;  // Should be 0.3, but often gives 0.30000000000000004

		=> Solution: Fixed point uses integers to represent decimals for perfect accuracy



	Constructor 1: Integer Input

		Fixed num(5); 
		What happens:
		5 × 256 = 1280
		Stores 1280 in _raw


	Constructor 2: Float Input

		Fixed num(5.75f);  // You want to represent 5.75
		5.75 × 256 = 1472
		Stores 1472 in _raw


	How Numbers are Stored in Memory ?? 

		=> Example 1: Fixed(5) - Integer Constructor

			Input: 5 
			Step 1: 5 × 256 = 1280
			Step 2: Store 1280 in _raw
			Memory: _raw = 1280 (binary: 00000101 00000000)


		=> Example 2: Fixed(5.75) - Float Constructor

			Input: 5.75 (decimal number)

			Step 1: 5.75 × 256 = 1472
			Step 2: Store 1472 in _raw

			Memory: _raw = 1472 (binary: 00000101 11000000)



	What Do These Binary Patterns Mean?

		=> binary representation:

			==> For 1280 (representing 5.0):
			
				Binary: 00000101 00000000
						└──┬──┘ └──┬──┘
						Integer  Fraction
						5       0.0	

			==> For 1472 (representing 5.75):

				Binary: 00000101 11000000
						└──┬──┘ └──┬──┘
						Integer  Fraction
						5      0.75



		Bit Position:  7   	6   	5   	4   	3   	2   		1   		0
		Power:       2⁻¹ 	2⁻² 	2⁻³  	2⁻⁴   	2⁻⁵    	2⁻⁶     	2⁻⁷      	2⁻⁸
		Value:       1/2 	1/4 	1/8 	1/16 	1/32 	1/64 		1/128 		1/256
		Decimal:     0.5 	0.25 	0.125 	0.0625 	0.03125 0.015625 	0.0078125 	0.00390625





	The Reverse Process ??

		Constructors convert from regular numbers → fixed-point

		toFloat()/toInt() convert from fixed-point → regular numbers

		
		1. toFloat()
			Converts fixed-point back to float (with decimals)\
			//converting FROM fixed-point TO IEEE 754 floating-point
			1 << _fractionalBits) = 1 << 8 = 256 (our scaling factor)
			static_cast<float>(this->_raw) = convert integer to float (so we get decimal division)
			
			=> Examples:
				Example 1: From 5.75

					Fixed num(5.75f);  // _raw = 1472 (from 5.75 × 256)

					float result = num.toFloat();
					Calculation: 1472 ÷ 256 = 5.75 ✓



		2. toInt()

			_raw >> _fractionalBits = _raw >> 8 (right shift by 8 bits)
			Right shift by 8 = divide by 256 and truncate (remove decimals)

			=> Example 1: From 5.75

				Fixed num(10.99f);  // _raw = 2813 (from 10.99 × 256 ≈ 2813)

				int result = num.toInt();
				Calculation: 2813 >> 8 = 10 (drops the 0.99) ✓

			
*/

