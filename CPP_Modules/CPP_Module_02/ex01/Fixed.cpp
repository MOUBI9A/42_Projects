/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:57:17 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/04 17:39:46 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nmBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (n << _nmBits);
}

Fixed::Fixed(const float float_point)
{
	std::cout << "Float constructor called" << std::endl; 
	this->_rawBits = std::roundf(float_point * (1 << _nmBits));
}
Fixed::Fixed(const Fixed& fxd)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fxd;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}


Fixed& Fixed::operator=(const Fixed& fxd)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fxd)
		this->_rawBits = fxd.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	// std::cout << "fff" << std::endl;
    os << fixed.toFloat();
    return os;
}


float Fixed::toFloat(void) const
{
	float to_float;
	to_float = (float)this->_rawBits / (1 << _nmBits);
	return (to_float);
}
int Fixed::toInt(void) const
{
	int to_int;
	to_int = (this->_rawBits >> _nmBits);
	return (to_int);
}