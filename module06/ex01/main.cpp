#include "Serializer.hpp"

int main (void)
{
	Data test = {8};
	Data *test1 = NULL;
	std::cout << test.prueba << std::endl;
	uintptr_t ptr =  Serializer::serialize(&test);
	test1 = Serializer::deserialize(ptr);
	std::cout << test1->prueba << std::endl;
}