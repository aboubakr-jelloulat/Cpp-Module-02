#include <iostream>
#include "Fixed.h"


void	SubjectTests(Fixed &a, Fixed const &b)
{
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

void	ArithmeticOperators(void)
{
	std::cout << "10 + 2 = " << (Fixed(10) + Fixed(2)) << std::endl;
	std::cout << "10 - 2 = " << (Fixed(10) - Fixed(2)) << std::endl;
	std::cout << "10 / 2 = " << (Fixed(10) / Fixed(2)) << std::endl;
	std::cout << "10 * 2 = " << (Fixed(10) * Fixed(2)) << std::endl;

}

void	ComparisonOperators()
{
    if (Fixed(2) > Fixed(1))
        std::cout << "✔ 2 > 1 : Passed" << std::endl;
    else
        std::cout << "✖ 2 > 1 : Failed" << std::endl;

    if (Fixed(1) < Fixed(2))
        std::cout << "✔ 1 < 2 : Passed" << std::endl;
    else
        std::cout << "✖ 1 < 2 : Failed" << std::endl;

    if (Fixed(2) >= Fixed(1))
        std::cout << "✔ 2 >= 1 : Passed" << std::endl;
    else
        std::cout << "✖ 2 >= 1 : Failed" << std::endl;

    if (Fixed(1) <= Fixed(1))
        std::cout << "✔ 1 <= 1 : Passed" << std::endl;
    else
        std::cout << "✖ 1 <= 1 : Failed" << std::endl;

    if (Fixed(2) == Fixed(2))
        std::cout << "✔ 2 == 2 : Passed" << std::endl;
    else
        std::cout << "✖ 2 == 2 : Failed" << std::endl;

    if (Fixed(2) != Fixed(1))
        std::cout << "✔ 2 != 1 : Passed" << std::endl;
    else
        std::cout << "✖ 2 != 1 : Failed" << std::endl;
}

int main()
{
	std::cout << std::endl << std::endl;

	Fixed	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	SubjectTests(a, b);

	//ArithmeticOperators();

	//ComparisonOperators();


	return 0;
}

/* Fixed-point math for b:
 * Fixed(5.05f): _raw = 1293 (5.05 × 256) 
 * Fixed(2): _raw = 512 (2 × 256)
 * Multiply: (1293 × 512) / 256 = 2586
 * toFloat(): 2586 / 256 = 10.1016
 */