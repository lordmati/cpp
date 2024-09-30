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
Fixed &Fixed::operator=(const Fixed &data)
{
	std::cout << "Call Copy assignment operator" << std::endl;
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