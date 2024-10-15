#include "Contact.hpp"

Contact::Contact()
{
	return ;
}
Contact::~Contact()
{
	return ;
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

void	Contact::printContact(void)
{
	std::cout << "First Name: " << this->FirstName << "\n";
	std::cout << "Last Name: " << this->LastName << "\n";
	std::cout << "Nickname: " << this->NickName << "\n";
	std::cout << "Number: " << this->Number << "\n";
	std::cout << "Secret: " << this->Secret << "\n";
}