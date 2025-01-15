#include "ScalarConverter.hpp"

bool isAlphabetic(const std::string& str)
{
	int i = 0;
	while(str[i])
	{
        if (!std::isalpha(str[i]))
            return false;
		i++;
    }
    return true;
}
bool isNumeric(const std::string& str)
{
	int i = 0;
    while(str[i])
	{
        if (!std::isdigit(str[i]))
            return false;
		i++;
    }
    return true;
}
int countChar(std::string str, char c)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return(count);
}

bool checkCaracter(std::string str)
{
	int i = 0;
	if((str[i] == '+' || str[i] == '-') || (str[i] >= '0' && str[i] <= '9'))
		i++;
	else
		return(false);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
	{
		if (str[i] == '.')
		{
			if ((str[i + 1] < '0' || str[i + 1] > '9'))
				return (false);
		}
		i++;
	}	
	if(str[i] == '\0')
		return(true);
	return(false);
}
bool checkLimits(std::string str,char c)
{
	if (c == 'l')
	{
		long numl = atol(str.c_str());
		if(numl < -2147483648 || numl > 2147483647)
			return(false);
		return(true);
	}
	if (c == 'f')
	{
		double numf = std::strtod(str.c_str(),NULL);
		if(numf > std::numeric_limits<float>::max() || numf < -std::numeric_limits<float>::max())
			return(false);
		return(true);
	}
	if (c == 'd')
	{
		long double numd = static_cast<long double>(std::strtod(str.c_str(),NULL));
		if(numd > std::numeric_limits<double>::max() || numd < -std::numeric_limits<double>::max())
			return(false);
		return(true);
	}
	return(false);
}
bool checkPoint(std::string str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == '.' && str[i + 1] == '0')
			return(true);
		i++;
	}
	return(false);
}
int checkType(std::string str)
{
	if(isNumeric(str) == true || str[0] == '+' || str[0] == '-')
		return(1);
	if(str.size() == 1 && str[0] >= 32 && str[0] <= 126)
		return(2);
	if (str == "nan" || str == "+nan")
		return(0);
	if (str == "-nan")
		return(7);
	if(str == "+inf" || str == "inf")
		return(3);
	if(str == "-inf")
		return(4);
	if(countChar(str,'.') == 1)
	{
		std::string aux = str;
		if (checkCaracter(str) == true && str[str.size() - 1] != '.')
			return(6);
		else if(checkCaracter(str.substr(0,str.size() - 1)) == true && aux[aux.size() - 1] == 'f')
			return(5);
	}
	return(-1);
}