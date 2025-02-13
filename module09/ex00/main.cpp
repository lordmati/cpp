#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Argument invalid" << std::endl;
		return(-1);
	}
	std::map<std::string, float> data;
	std::ifstream file("data.csv");
	std::ifstream input(argv[1]);
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "Error open file" << std::endl;
		return(-1);
	}
	while(std::getline(file,line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		if (std::getline(ss,date,',') && ss >> value)
			data[date] = value;
	}
	if(!input.is_open())
	{
		std::cerr << "Error open input" << std::endl;
		file.close();
		return(-1);
	}
	while(std::getline(input, line))
	{
		std::stringstream ss(line);
		std::string date;
		double inputValue;
		if(std::getline(ss,date,'|') && ss >> inputValue)
		{
			date.erase(0,date.find_first_not_of(" \t"));
			date.erase(date.find_last_not_of(" \t") + 1);
			if(!isValidDate(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			if(inputValue < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if(inputValue > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue; 
			}
			std::map<std::string,float>::iterator it = data.find(date);
			if (it == data.end())
			{
				std::map<std::string,float>::iterator it = data.lower_bound(date);
				if(it == data.begin())
				{
					std::cout << "Error: bad input => " << date << std::endl;
					continue;
				}
				if(it == data.end())
					it--;
				float result = it->second * inputValue;
				std::cout << date << " => " << inputValue << " = " << result << std::endl;
			}
			if(it != data.end())
			{
				float result = it->second * inputValue;
				std::cout << date << " => " << inputValue << " = " << result << std::endl;
			}
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}
	file.close();
	input.close();
	return 0;
}
