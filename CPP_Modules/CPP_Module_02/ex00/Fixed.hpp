/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:10:09 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/04 17:18:50 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& fxd );
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
		Fixed& operator=(const Fixed& fxd);

	private:
		int _rawBits;
		static const int _nmBits;
};

#endif