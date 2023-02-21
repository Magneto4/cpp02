#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b(-2.3f);
	Fixed		c(a);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "max a b " << Fixed::max (a, b) << std::endl;
	std::cout << "min a b " << Fixed::min (a, b) << std::endl;
}
