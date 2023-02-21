#include "Fixed.hpp"
#include <iostream>
#include <limits.h>
#include <math.h>

float	ft_pow(int x, int n)
{
	int	res = 1;
	while (n > 0)
	{
		res *= x;
		n --;
	}
	return (res);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_n = src.getRawBits();
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << this->_point;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	float	res = x * ft_pow(2, this->_point);
	res = roundf(res);
	this->_n = (int)res;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & fixed)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		this->_n = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

int Fixed::toInt(void) const
{
	return (this->_n >> this->_point);
}

float Fixed::toFloat(void) const
{
	float	res;

	res = (float)this->_n / pow(2, this->_point);
	return (res);
}


std::ostream &	operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}
