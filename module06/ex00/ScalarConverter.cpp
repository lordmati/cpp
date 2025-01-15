#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructor ScalarConverter" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor ScalarConverter" << std::endl;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &data)
{
	if(this != &data)
		*this = data;
	return(*this);
}
ScalarConverter::ScalarConverter(const ScalarConverter &data)
{
	std::cout << "ScalarConverter constructor copy" << std::endl;
	(void)data;
}
void ScalarConverter::convert(std::string str)
{
	int num = checkType(str);
	switch (num)
	{
		case 0:
			printNan(true);
			return ;
		case 1:
			printNum(atoi(str.c_str()),str);
			return ;
		case 2:
			printChar(str[0]);
			return ;
		case 3:
			printInf(true);
			return;
		case 4:
			printInf(false);
			return;
		case 5:
			printFloat(std::strtof(str.c_str(),NULL),checkPoint(str),str);
			return;
		case 6:
			printDouble(std::strtod(str.c_str(),NULL),checkPoint(str),str);
			return;
		case 7:
			printNan(false);
			return;
		default:
			std::cerr << "Error: Invalid data type" << std::endl;
			return;
	}
}