#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{
	private:

	public:
			ScavTrap();
			ScavTrap &operator=(const ScavTrap &data);
			ScavTrap(const ScavTrap &data);
			ScavTrap(std::string name);
			void guardGate();
			~ScavTrap();
};

#endif