#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "Constructor Human B" << "\n";
	weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "Destructor Human B" << "\n";
	return ;
}

void HumanB::attack()
{
	if (!this->weapon)
		std::cout << "He doesnt have a weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}