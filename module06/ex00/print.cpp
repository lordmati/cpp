#include "ScalarConverter.hpp"

void printNan(bool flag)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (flag == true)
	{
    	std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
    	std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
	else
	{
		std::cout << "float: " << -std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
    	std::cout << "double: " << -std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
}
void printNum(int num,std::string str)
{
	if (num >= 32 && num <= 126)
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
	else if (num < 0 || num > 255)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (checkLimits(str,'l') == true)
	{
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		if(num < 1000000 && num > 0.0001)
		{
			std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
			std::cout << "double: " << static_cast<double>(num) << ".0 "<< std::endl;
		}
		else if(num > -1000000 && num < -0.0001)
		{
			std::cout << "float: " << static_cast<float>(num) << ".0f"<< std::endl;
			std::cout << "double: " << static_cast<double>(num) << ".0 "<< std::endl;
		}
		else
		{
			std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
			std::cout << "double: " << static_cast<double>(num) << std::endl;
		}
		return ;
	}
	else
		std::cout << "int: impossible" << std::endl;
	if(checkLimits(str,'f') == true)
	{
		std::cout << "float: " << std::strtof(str.c_str(),NULL) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(std::strtof(str.c_str(),NULL)) << std::endl;
	}
	else if(checkLimits(str,'d') == true)
	{
		std::cout << "float: imposibble" << std::endl;
		std::cout << "double: " << static_cast<double>(std::strtod(str.c_str(),NULL)) << ".0" << std::endl;
	}
}
void printChar (char c)
{
	std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void printInf(bool flag)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if(flag == true)
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
}
void printFloat(float num,bool zero,std::string str)
{
	if (checkLimits(str,'f') == true)
	{
		if (num >= 32 && num <= 126)
			std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
		else if (num < 0 || num > 255)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if(checkLimits(str,'l') == true)
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		//std::cout << std::fixed << std::setprecision(10); COMENTARSELO A DEPA
		if(zero == true && (std::atoi(str.c_str()) < 1000000 && std::atoi(str.c_str()) > 0.0001))
		{
			std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
		}
		else if (zero == true && (std::atoi(str.c_str()) > -1000000 && std::atoi(str.c_str()) < -0.0001))
		{
			std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(num) << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		if (checkLimits(str,'d') == true)
		{
			if(zero == true)
				std::cout << "double: " << static_cast<double>(std::strtod(str.c_str(),NULL)) << ".0" << std::endl;
			else
				std::cout << "double: " << static_cast<double>(std::strtod(str.c_str(),NULL)) << std::endl;
		}
		else
			std::cout << "double: impossible" << std::endl;
	}
}
void printDouble(double num,bool zero,std::string str)
{
	if (checkLimits(str,'d') == true)
	{
		if (num >= 32 && num <= 126)
			std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
		else if (num < 0 || num > 255)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (checkLimits(str,'l') == true)
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if(checkLimits(str,'f') == true)
		{
			if(zero == true && (std::atoi(str.c_str()) < 1000000 && std::atoi(str.c_str()) > 0.0001))
			{
				std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
			}
			else if (zero == true && (std::atoi(str.c_str()) > -1000000 && std::atoi(str.c_str()) < -0.0001))
			{
				std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(num) << std::endl;
			}
			else
			{
				std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(num) << std::endl;			
			}
			return;
		}
		else
		{
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: " << static_cast<double>(num) << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}