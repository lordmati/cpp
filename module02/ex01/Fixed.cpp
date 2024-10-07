#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default Constructor called" << std::endl;
	this->Number = 0;
}
Fixed::~Fixed(void)
{
	std::cout << "Call destructor" << std::endl;
}
Fixed::Fixed(const Fixed &data)
{
	std::cout << "Call copy constructor " << std::endl;
	this->Number = data.Number;
}
Fixed::Fixed(int num)
{
	std::cout << "Call int num constructor" << std::endl;
	//convertir num a fixpoint y guardarlo
	this->Number = num << bits;
}
Fixed::Fixed(float num)
{
	std::cout << "Call float num constructor" << std::endl;
	//convertir float a fixpoint y guardarlo
	this->Number = static_cast<int>(num * (roundf(1 << bits)));
}
float Fixed::toFloat( void ) const
{
	return(this->Number / (round(1 << bits)));
}
int Fixed::toInt( void ) const
{
	return(this->Number >> bits);
}
std::ostream  &operator<<(std::ostream &ret, const Fixed &data)
{
	std::cout << "Call Copy assignment operator <<" << std::endl;
	ret << data.toFloat();
	return ret;
}

Fixed &Fixed::operator=(const Fixed &data)
{
	std::cout << "Call Copy assignment operator =" << std::endl;
	if(this == &data)
		return(*this);
	this->setRawBits(data.getRawBits());
	return(*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->Number);
}
void Fixed::setRawBits(int const raw)
{
	this->Number = raw;
}