#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"

class Brain
{
	private:
			std::string ideas[100];
	public:
			Brain();
			Brain(const Brain &data);
			Brain &operator=(const Brain &data);
			~Brain();
};


#endif