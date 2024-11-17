#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) , name(name)
{
	std::cout << "Constructor Human A" << "\n";
}

HumanA::~HumanA()
{
	std::cout << "Destructor Human A" << "\n";
	return ;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}