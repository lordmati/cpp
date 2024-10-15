#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Call Cat default constructor" << std::endl;
}
Cat::Cat(Cat const &data) : Animal ()
{
	std::cout << "Call Cat copy constructor " << std::endl;
	this->type = data.type;
}

Cat &Cat::operator=(const Cat &data)
{
	std::cout << "Call Cat Copy assignment operator" << std::endl;
	if(this != &data)
	{
		*this = data;
	}
	return(*this);
}
Cat::~Cat(void)
{
	std::cout << "Call Cat destructor default" << std::endl;
}
void Cat::makeSound(void) const
{
	std::cout << "Prrr Meow" << std::endl;
}
