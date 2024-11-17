#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string newtype)
{
	this->type = newtype;
	std::cout << "Weapon Builder." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon Destroyer" << "\n";
	return ;
}

const std::string Weapon::getType()
{
	return(this->type);
}
void  Weapon::setType(std::string t)
{
	type = t;
	return;
}