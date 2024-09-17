#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "Constructora Human B" << "\n";
}

HumanB::~HumanB()
{
	std::cout << "Destructora Human B" << "\n";
	return ;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}