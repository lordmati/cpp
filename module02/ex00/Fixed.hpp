#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Fixed
{
	private:
			int Number;
			static const int bits;
	public:
			Fixed();
			Fixed(const Fixed &data);
			Fixed &operator=(const Fixed &data);
			int getRawBits(void) const;
			void setRawBits(int const raw);
			~Fixed();
};

#endif