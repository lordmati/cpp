#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) , name(name)
{
	std::cout << "Constructora Human A" << "\n";
}

HumanA::~HumanA()
{
	std::cout << "Destructora Human A" << "\n";
	return ;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}