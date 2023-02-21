
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int	_n;
	static const int	_point = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int n);
	Fixed(const float x);
	~Fixed();

	Fixed&	operator=(const Fixed & src);
	Fixed	operator+(const Fixed & r) const;
	Fixed	operator-(const Fixed & r) const;
	Fixed	operator*(const Fixed & r) const;
	Fixed	operator/(const Fixed & r) const;

	int	operator>(Fixed const & r) const;
	int	operator<(Fixed const & r) const;
	int	operator>=(Fixed const & r) const;
	int	operator<=(const Fixed & r) const;
	int	operator==(const Fixed & r) const;
	int	operator!=(const Fixed & r) const;

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static const Fixed&	max(const Fixed& a, const Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static Fixed&		min(Fixed& a, Fixed& b);

	int	getRawBits( void ) const;
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);

#endif
