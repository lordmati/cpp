# include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}
Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie()
{
	std::cout << "Killing: " << this->name << "\n";
	return;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
