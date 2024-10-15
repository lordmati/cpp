#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string Number;
		std::string Secret;
	public:
		void setContact(std::string contact,std::string compare);
		std::string getContact(std::string search);
		void	printContact(void);
		Contact();
		~Contact();
};

#endif