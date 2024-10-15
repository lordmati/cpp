#include "PhoneBook.hpp"

int main (void)
{
	PhoneBook book;
	std::string option;
	do
	{	
		option.erase();
		std::cout << "CHOOSE ONE OPTION\n";
		std::cout << "-> ADD\n";
		std::cout << "-> SEARCH\n";
		std::cout << "-> EXIT\n";
		std::getline(std::cin,option);
		if (std::cin.eof() || !std::cin.good())
			exit(1);
		if (option == "ADD")
			book.addContact();
		else if (option == "SEARCH")
			book.searchFunction();
		else if (!option.empty() && option != "EXIT")
			std::cout << "INVALID OPTION\n";
	} while(option != "EXIT");
}
