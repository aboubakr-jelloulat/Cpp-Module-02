#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.h"


Fixed::Fixed() : _raw(0) { }

Fixed::Fixed(Fixed const &other) {*this = other;}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_raw = other._raw;

	return *this;
}

Fixed::Fixed(int const i)  {this->_raw = i << _fractionalBits;}

Fixed::Fixed(float const f)  {this->_raw = roundf(f * (1 << _fractionalBits));}

float Fixed::toFloat(void) const {return static_cast<float>(this->_raw) / (1 << _fractionalBits);}

int Fixed::toInt(void) const  {return this->_raw >> _fractionalBits;}

int	Fixed::getRawBits( void ) const {return this->_raw;}

void Fixed::setRawBits( int const raw ) {this->_raw = raw;}

Fixed::~Fixed()	{}


std::ostream& operator<<(std::ostream& out, Fixed const &f) {return out << f.toFloat(); }



// The 6 comparison operators: >, <, >=, <=, ==, and !=


bool Fixed::operator > (const Fixed &other)const {return this->_raw > other.getRawBits(); }

bool Fixed::operator < (const Fixed &other)const {return this->_raw < other.getRawBits(); }

bool Fixed::operator >= (const Fixed &other)const {return this->_raw >= other.getRawBits(); }

bool Fixed::operator <= (const Fixed &other)const {return this->_raw <= other.getRawBits(); }

bool Fixed::operator == (const Fixed &other)const {return this->_raw == other.getRawBits(); }

bool Fixed::operator != (const Fixed &other)const {return this->_raw != other.getRawBits(); }


// The 4 arithmetic operators: +, -, *, and /

Fixed Fixed::operator+(const Fixed &other)const { return Fixed(this->toFloat() + other.toFloat()); }

Fixed Fixed::operator-(const Fixed &other)const { return Fixed(this->toFloat() - other.toFloat()); }

Fixed Fixed::operator*(const Fixed &other)const { return Fixed(this->toFloat() * other.toFloat()); }

Fixed Fixed::operator/(const Fixed &other)const { return Fixed(this->toFloat() / other.toFloat()); }


// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators


Fixed& Fixed::operator++() { this->_raw++;   return *this; /* Return reference to modified object */ }

Fixed Fixed::operator++(int) 
{
	Fixed old(*this);

	++(*this);
	
	return old;
}


Fixed& Fixed::operator--()	{this->_raw--; return *this;}

Fixed Fixed::operator--(int) 
{
	Fixed old(*this);

	--(*this);
	
	return old;
}

Fixed&	Fixed::min(Fixed &lhs, Fixed &rhs)	{	return (lhs < rhs) ? lhs : rhs;	}

Fixed const&	Fixed::min(Fixed const &lhs, Fixed const &rhs) {	return (lhs < rhs) ? lhs : rhs;	}


Fixed&	Fixed::max(Fixed &lhs, Fixed &rhs)	{	return (lhs > rhs) ? lhs : rhs;	}

Fixed const&	Fixed::max(Fixed const &lhs, Fixed const &rhs)	{	return (lhs > rhs) ? lhs : rhs;	}


//  *** Exercise 03: BSP *** 