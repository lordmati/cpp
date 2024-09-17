#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &rfs = str;

	std::cout << &str << "\n";
	std::cout << ptr << "\n";
	std::cout << &rfs << "\n";

	std::cout << str << "\n";
	std::cout << *ptr << "\n";
	std::cout << rfs << "\n";
}