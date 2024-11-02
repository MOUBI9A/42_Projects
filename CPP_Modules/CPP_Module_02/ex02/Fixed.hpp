
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
		Fixed(const Fixed& fxd);
		Fixed(const int n);
		Fixed(const float float_point);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
		Fixed& operator=(const Fixed& fxd );
		bool operator>(const Fixed& second_side);
		bool operator<(const Fixed& second_side);
		bool operator>=(const Fixed& second_side);
		bool operator<=(const Fixed& second_side);
		bool operator==(const Fixed& second_side);
		bool operator!=(const Fixed& second_side);

		Fixed operator+(const Fixed& second_side);
		Fixed operator-(const Fixed& second_side);
		Fixed operator*(const Fixed& second_side);
		Fixed operator/(const Fixed& second_side);
	
		Fixed& operator--();
		Fixed& operator++();
		Fixed operator--(int);
		Fixed operator++(int);

		static Fixed& min(Fixed& fixed_one, Fixed& fxd_two);
		static Fixed& max(Fixed& fixed_one, Fixed& fxd_two);

		static const Fixed& min(const Fixed& fixed_one, const Fixed& fxd_two);
		static const Fixed& max(const Fixed& fixed_one, const Fixed& fxd_two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif