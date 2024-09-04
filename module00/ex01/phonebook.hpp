#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
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
		void	printcontact(void);
		Contact();
		~Contact();
};

class Phonebook
{
	private:
		Contact people[8];
		int	index;
		int count_people;
	public:
		Phonebook();
		~Phonebook();
		void addContact();
		void searchfunction();

};

#endif