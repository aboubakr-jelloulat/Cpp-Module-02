#pragma once

#include <iostream>

class Fixed 
{
private:
    int _raw;
    static const int _fractionalBits = 8;

public:
    // Orthodox 
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    Fixed(int const i);
    Fixed(float const f);


    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

	// 6 comparison operators: >, <, >=, <=, ==, and !=
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // 4 arithmetic operators: +, -, *, and /
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // 4 increment/decrement
    Fixed& operator++();       // ++Prefix
    Fixed operator++(int);     // Postfix++
    Fixed& operator--();       // --Prefix
    Fixed operator--(int);     // Postfix--

    // Static member functions
    static Fixed& min(Fixed& lhs, Fixed& rhs);
    static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed& max(Fixed& lhs, Fixed& rhs);
    static const Fixed& max(const Fixed& lhs, const Fixed& rhs);


	// **** Exercise 03: BSP ****


};

std::ostream& operator<<(std::ostream& out, const Fixed& f);
