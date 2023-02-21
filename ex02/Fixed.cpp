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
	this->_n = 0;
}

Fixed::Fixed(const Fixed&src)
{
	this->_n = src.getRawBits();
}

Fixed::Fixed(const int n)
{
	this->_n = n << this->_point;
}

Fixed::Fixed(const float x)
{
	float	res = x * ft_pow(2, this->_point);
	res = roundf(res);
	this->_n = (int)res;
}

Fixed::~Fixed()
{
}

//arithmetic operators

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		this->_n = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& r) const
{
	Fixed	res(this->toFloat() + r.toFloat());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& r) const
{
	Fixed	res(this->toFloat() - r.toFloat());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& r) const
{
	Fixed	res(this->toFloat() * r.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed& r) const
{
	Fixed	res(this->toFloat() / r.toFloat());
	return (res);
}

//comparators

int	Fixed::operator>(Fixed const & r) const
{
	return (this->toFloat() > r.toFloat());
}

int	Fixed::operator<(Fixed const & r) const
{
	return (this->toFloat() < r.toFloat());
}

int	Fixed::operator>=(Fixed const & r) const
{
	return (this->toFloat() >= r.toFloat());
}

int	Fixed::operator<=(Fixed const & r) const
{
	return (this->toFloat() <= r.toFloat());
}

int	Fixed::operator==(Fixed const & r) const
{
	return (this->toFloat() == r.toFloat());
}

int	Fixed::operator!=(Fixed const & r) const
{
	return (this->toFloat() != r.toFloat());
}

//incr and decr

Fixed&	Fixed::operator++()
{
	this->_n ++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_n ++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_n --;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_n --;
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
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

//max min

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}
