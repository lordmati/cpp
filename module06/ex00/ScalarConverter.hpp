#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
	public:
			static void convert(std::string str);
	private:
			ScalarConverter();
			~ScalarConverter();
			ScalarConverter &operator=(const ScalarConverter &data);
			ScalarConverter(const ScalarConverter &data);
};
int checkType(std::string str);
bool checkLimits(std::string str,char c);
bool checkPoint(std::string str);
void printNan(bool flag);
void printNum(int num,std::string str);
void printChar (char c);
void printInf(bool flag);
void printFloat(float num,bool zero,std::string str);
void printDouble(double num,bool zero,std::string str);
#endif