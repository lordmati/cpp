#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor" << std::endl;
}
Serializer &Serializer::operator=(const Serializer &data)
{
	if(this != &data)
		*this = data;
	return(*this);
}
Serializer::Serializer(const Serializer &data)
{
	std::cout << "Serializer constructor copy" << std::endl;
	(void)data;
}
Serializer::~Serializer()
{
	std::cout << "Serializer destructor" << std::endl;
}