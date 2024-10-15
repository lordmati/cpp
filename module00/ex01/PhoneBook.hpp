#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact people[8];
		int	index;
		int count_people;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchFunction();
};

#endif