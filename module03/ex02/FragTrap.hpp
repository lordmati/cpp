#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected:

	public:
			FragTrap();
			FragTrap &operator=(const FragTrap &data);
			FragTrap(std::string name);
			FragTrap(const FragTrap &data);
			void highFivesGuys(void);
			~FragTrap();
};


#endif