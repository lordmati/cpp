#include "BitcoinExchange.hpp"

bool isValidDate(const std::string &date)
{
	if(date.length() != 10)
		return(false);
	if(date[4] != '-' || date[7] != '-')
		return(false);
	std::string year = date.substr(0,4);
	std::string month = date.substr(5,2);
	std::string day = date.substr(8,2);
	int y = std::atoi(year.c_str());
	int m = std::atoi(month.c_str());
	int d = std::atoi(day.c_str());
	if (m < 1 || m > 12)
		return(false);
	if(month == "01" || month == "03" || month == "05"
		|| month == "07" || month == "08" || month == "10" || month == "12")
	{
		if (d < 1 || d > 31)
			return(false);
	}
	if (month == "04" || month == "06" || month == "09" || month == "11")
	{
		if(d < 1 || d > 30)
			return(false);
	}
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		if (month == "02")
		{
			if(d < 1 || d > 29)
				return(false);
		}
	}
	else
	{
		if(month == "02")
		{
			if (d < 1 || d > 28)
				return(false);
		}
	}
	return(true);
}