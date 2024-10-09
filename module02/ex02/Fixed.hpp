#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Fixed
{
	private:
			int Number;
			static const int bits = 8;
	public:
			Fixed();
			Fixed(const Fixed &data);

			Fixed &operator=(const Fixed &data);
			static Fixed &min(Fixed &a, Fixed &b);
			static Fixed &max(Fixed &a, Fixed &b);
			static const Fixed &min(const Fixed &a,const Fixed &b);
			static const Fixed &max(const Fixed &a,const Fixed &b);
			//Comparision operators
			bool operator==(const Fixed &data);
			bool operator>(const Fixed &data);
			bool operator<(const Fixed &data);
			bool operator!=(const Fixed &data);
			bool operator>=(const Fixed &data);
			bool operator<=(const Fixed &data);

			//Arithmetics
			Fixed operator+(const Fixed &data);
			Fixed operator-(const Fixed &data);
			Fixed operator*(const Fixed &data);
			Fixed operator/(const Fixed &data);

			//Increment / Decrement
			Fixed &operator--();
			Fixed &operator++();
			Fixed operator++(int);
			Fixed operator--(int);

			Fixed(int num);
			Fixed(float num);
			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat( void ) const;
			int toInt( void ) const;
			~Fixed();
};

std::ostream& operator<<(std::ostream& ret, const Fixed& data);

#endif