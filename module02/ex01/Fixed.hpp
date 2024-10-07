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
			Fixed(int num);
			Fixed(float num);
			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat( void ) const;
			int toInt( void ) const;
			~Fixed();
};

std::ostream  &operator<<(std::ostream &ret, const Fixed &data);

#endif