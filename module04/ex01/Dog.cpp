#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Call Dog default constructor" << std::endl;
}
Dog::Dog(Dog const &data) : Animal ()
{
	std::cout << "Call Dog copy constructor " << std::endl;
	this->type = data.type;
}

Dog &Dog::operator=(const Dog &data)
{
	std::cout << "Call Dog Copy assignment operator" << std::endl;
	if(this != &data)
	{
		*this = data;
	}
	return(*this);
}
Dog::~Dog(void)
{
	std::cout << "Call Dog destructor default" << std::endl;
}
void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}