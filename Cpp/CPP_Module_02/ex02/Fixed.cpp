
#include "Fixed.hpp"

const int Fixed::_nmBits = 8;

Fixed::Fixed(void)
{
	this->_rawBits = 0;
}
Fixed::Fixed(const int n)
{
	this->_rawBits = (n << _nmBits);
}

Fixed::Fixed(const float float_point)
{
	this->_rawBits = std::roundf(float_point * (1 << _nmBits));
}
Fixed::Fixed( const Fixed& fxd )
{
	*this = fxd;
}

Fixed::~Fixed(void)
{

}

int Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}


float Fixed::toFloat( void ) const
{
	float to_float;
	to_float = (float)this->_rawBits / (1 << _nmBits);
	return (to_float);
}
int Fixed::toInt( void ) const
{
	int to_int;
	to_int = (this->_rawBits >> _nmBits);
	return (to_int);
}

Fixed& Fixed::operator=( const Fixed& fxd)
{
	if (this != &fxd)
		this->_rawBits = fxd.getRawBits();
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>( const Fixed& second_side)
{
	return (this->_rawBits > second_side.getRawBits());
}

bool Fixed::operator<( const Fixed& second_side)
{
	return (this->_rawBits < second_side.getRawBits());
}

bool Fixed::operator>=( const Fixed& second_side)
{
	return (this->_rawBits >= second_side.getRawBits());
}

bool Fixed::operator<=( const Fixed& second_side)
{
	return (this->_rawBits <= second_side.getRawBits());
}

bool Fixed::operator==( const Fixed& second_side)
{
	return (this->_rawBits == second_side.getRawBits());
}

bool Fixed::operator!=( const Fixed& second_side)
{
	return (this->_rawBits != second_side.getRawBits());
}

Fixed Fixed::operator+(const Fixed& second_side)
{
	Fixed add_op(this->toFloat() + second_side.toFloat());
	return (add_op);
}

Fixed Fixed::operator-(const Fixed& second_side)
{
	Fixed sub_op(this->toFloat() - second_side.toFloat());
	return (sub_op);
}

Fixed Fixed::operator*(const Fixed& second_side)
{
	Fixed mult_op(this->toFloat() * second_side.toFloat());
	return (mult_op);
}

Fixed Fixed::operator/(const Fixed& second_side)
{
	Fixed div_op(this->toFloat() / second_side.toFloat());
	return (div_op);
}

Fixed& Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed& Fixed::operator++()
{
	++this->_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->_rawBits;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->_rawBits;
	return (tmp);
}

Fixed& Fixed::min( Fixed& fixed_one, Fixed& fxd_two )
{
	return (fixed_one < fxd_two ? fixed_one : fxd_two);
}

Fixed& Fixed::max( Fixed& fixed_one, Fixed& fxd_two )
{
	return (fixed_one > fxd_two ? fixed_one : fxd_two);
}

const Fixed& Fixed::min( const Fixed& fixed_one, const Fixed& fxd_two )
{
	return (fixed_one.getRawBits() < fxd_two.getRawBits() ? fixed_one : fxd_two);
}

const Fixed& Fixed::max( const Fixed& fixed_one, const Fixed& fxd_two )
{
	return (fixed_one.getRawBits() > fxd_two.getRawBits() ? fixed_one : fxd_two);
}