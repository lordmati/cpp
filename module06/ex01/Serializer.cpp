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
uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t ret;
	ret = reinterpret_cast<uintptr_t>(ptr);
	return(ret);
}
Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ret;
	ret = reinterpret_cast<Data*>(raw);
	return(ret);
}