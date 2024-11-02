/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:28:24 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/04 17:39:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _nmBits;
	public:
		Fixed(void);
		Fixed( const Fixed& fxd );
		Fixed(const int n);
		Fixed(const float float_point);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
		Fixed& operator=( const Fixed& fxd );
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );
#endif