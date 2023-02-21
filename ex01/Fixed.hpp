
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

	Fixed	&operator=(const Fixed & src);
	int	getRawBits( void ) const;
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);

#endif
