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
	this->Number = static_cast<int>(roundf(num * (1 << bits)));
}
float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->Number) / (1 << bits);
}
int Fixed::toInt( void ) const
{
	return(this->Number >> bits);
}
std::ostream& operator<<(std::ostream& ret, const Fixed& data)
{
	ret << data.toFloat();
	return ret;
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

Fixed &Fixed::operator=(const Fixed &data)
{
	std::cout << "Call Copy assignment operator" << std::endl;
	if(this == &data)
		return(*this);
	this->setRawBits(data.getRawBits());
	return(*this);
}

Fixed &Fixed::max(Fixed &a,Fixed &b)
{
	if(a < b)
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a,const Fixed &b)
{
	if(a.Number < b.Number)
		return b;
	return a;
}

Fixed &Fixed::min(Fixed &a,Fixed &b)
{
	if(a > b)
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed &a,const Fixed &b)
{
	if(a.Number > b.Number)
		return b;
	return a;
}
///Comparison

bool Fixed::operator>(const Fixed &data)
{
	if(this->Number > data.Number)
		return(true);
	return false;
}

bool Fixed::operator==(const Fixed &data)
{
	if(this->Number == data.Number)
		return(true);
	return false;
}

bool Fixed::operator<(const Fixed &data)
{
	if(this->Number < data.Number)
		return(true);
	return false;
}

bool Fixed::operator!=(const Fixed &data)
{
	if(this->Number != data.Number)
		return(true);
	return false;
}

bool Fixed::operator>=(const Fixed &data)
{
	if(this->Number >= data.Number)
		return(true);
	return false;
}

bool Fixed::operator<=(const Fixed &data)
{
	if(this->Number <= data.Number)
		return(true);
	return false;
}

///Arithmetics

Fixed Fixed::operator+(const Fixed &data)
{
	return (this->toInt() + data.toInt());
}

Fixed Fixed::operator-(const Fixed &data)
{
	return (this->toInt() - data.toInt());
}

Fixed Fixed::operator*(const Fixed &data)
{
	return (this->toFloat() * data.toFloat());
}

Fixed Fixed::operator/(const Fixed &data)
{
	return (this->toFloat() / data.toFloat());
}

//Pre Increment 

Fixed &Fixed::operator++()
{
	this->Number++;
	return(*this);
}
 
// Post Increment

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);
	this->Number++;
	return(aux);
}

// Pre Decrement

Fixed &Fixed::operator--()
{
	this->Number--;
	return(*this);
}

// Post Decrement

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);
	this->Number--;
	return(aux);
}