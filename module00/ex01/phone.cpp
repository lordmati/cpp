#include "phonebook.hpp"

Phonebook::Phonebook()
{
	index = 0;
	count_people = 0;
}

Phonebook::~Phonebook()
{
	return ;
}
Contact::Contact()
{
	return ;
}
Contact::~Contact()
{
	return ;
}

int	indexreturn(std::string number)
{
	if (number == "1")
		return(1);
	else if (number == "2")
		return(2);
	else if (number == "3")
		return(3);
	else if (number == "4")
		return(4);
	else if(number == "5")
		return(5);
	else if (number == "6")
		return(6);
	else if (number == "7")
		return(7);
	else if (number == "8")
		return(8);
	else
		return(0);
}

void	Contact::printcontact(void)
{
	std::cout << "First Name: " << this->FirstName << "\n";
	std::cout << "Last Name: " << this->LastName << "\n";
	std::cout << "Nickname: " << this->NickName << "\n";
	std::cout << "Number: " << this->Number << "\n";
	std::cout << "Secret: " << this->Secret << "\n";
}

std::string Contact::getContact(std::string search)
{
	if(search == "firstname")
	{
		if (this->FirstName.length() < 10)
			return(this->FirstName);
		else
			return(this->FirstName.substr(0,9) + ".");
	}
	else if (search == "lastname")
	{
		if (this->LastName.length() < 10)
			return(this->LastName);
		else
			return(this->LastName.substr(0,9) + ".");		
	}
	else if (search == "nickname")
	{
		if (this->NickName.length() < 10)
			return(this->NickName);
		else
			return(this->NickName.substr(0,9) + ".");
	}
	return "";
}

bool ft_isdigit(std::string str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (false);
	}
	return (true);
}

void Phonebook::searchfunction()
{
	int i = 0;
	std::string number = "";
	if(this->count_people == 0)
	{
		std::cout << "LIST CONTACT EMPTY\n";
		return ;
	}
	else
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::cout << "|| INDEX || FIRST NAME || LAST NAME || NICKNAME ||\n";
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		while(i < this->count_people)
		{
			std::cout << "||" << std::setw(7) << 1 + i;
			std::cout << "||" << std::setw(12) << people[i].getContact("firstname");
			std::cout << "||" << std::setw(11) << people[i].getContact("lastname");
			std::cout << "||" << std::setw(10) << people[i].getContact("nickname");
			std::cout << "||\n";
			std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			i++;
		}
		std::cout << "CHOOSE AN INDEX " << 1 << " TO " << this->count_people << "\n";
		while(1)
		{
			number = "";
			while(number == "")
			{
				std::getline(std::cin,number);
				if (std::cin.eof() || !std::cin.good())
					exit(1);
			}
			if (!ft_isdigit(number))
			{
				std::cout << "PLEASE CHOOSE A VALID OPTION\n";
				number.erase();
			}
			else
			{
				if (!indexreturn(number))
				{
					std::cout << "PLEASE CHOOSE A VALID OPTION\n";
					number.erase();
				}
				else
				{
					if (indexreturn(number) <= this->count_people)
					{
						this->people[indexreturn(number) - 1].printcontact();
						return ;
					}
					else
					{
						std::cout << "PLEASE CHOOSE A VALID OPTION\n";
						number.erase();
					}
				}
			}
		}
	}
}

void Contact::setContact(std::string people,std::string compare)
{
	if(compare == "firstname")
		this->FirstName = people;
	else if (compare == "lastname")
		this->LastName = people;
	else if (compare == "nickname")
		this->NickName = people;
	else if (compare == "number")
		this->Number = people;
	else if (compare == "secret")
		this->Secret = people;
}

void Phonebook::addContact(void)
{
	Contact people;

	std::string argument = "";
	while(argument == "")
	{
		std::cout << "First Name: ";
		std::getline(std::cin,argument);
		if (std::cin.eof() || !std::cin.good())
			exit(1);
	}
	people.setContact(argument,"firstname");
	argument.erase();

	argument = "";
	while(argument == "")
	{
		std::cout << "Last Name: ";
		std::getline(std::cin,argument);
		if (std::cin.eof() || !std::cin.good())
			exit(1);
	}
	people.setContact(argument,"lastname");
	argument.erase();

	argument = "";
	while(argument == "")
	{
		std::cout << "Nickname: ";
		std::getline(std::cin,argument);
		if (std::cin.eof() || !std::cin.good())
			exit(1);
	}
	people.setContact(argument,"nickname");
	argument.erase();

	while(1)
	{
		argument = "";
		while(argument == "")
		{
			std::cout << "Number: ";
			std::getline(std::cin,argument);
			if (std::cin.eof() || !std::cin.good())
				exit(1);
		}
		if (!ft_isdigit(argument))
			std::cout << "PLEASE ENTER ONLY NUMBER\n";
		else 
			break;
	}
	people.setContact(argument,"number");
	argument.erase();

	argument = "";
	while(argument == "")
	{
		std::cout << "Secret: ";
		std::getline(std::cin,argument);
		if (std::cin.eof() || !std::cin.good())
			exit(1);
	}
	people.setContact(argument,"secret");
	argument.erase();

	this->people[this->index] = people;
	this->index = (this->index + 1) % 8;
	if (this->count_people < 8)
		this->count_people++;
}

int main (void)
{
	Phonebook book;
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
			book.searchfunction();
		else if (!option.empty() && option != "EXIT")
			std::cout << "INVALID OPTION\n";
	} while(option != "EXIT");
}
