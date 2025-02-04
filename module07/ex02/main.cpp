#include "Array.hpp"

int main (void)
{
	try
	{
		Array<int> test1(20);
		Array<int> test2(5);
		Array<int> test3(7);
		//Array<int> test5(-1);
		std::cout << "Test.1 : " << test1.size() << std::endl;
		std::cout << "Test.2 : " << test2.size() << std::endl;
		std::cout << "Test.3 : " << test3.size() << std::endl;
		//std::cout << test3[8] << std::endl;
		test1[0] = 1;
		Array<int> copy(test1);
		test1[0] = 50;
		std::cout << copy[0] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}