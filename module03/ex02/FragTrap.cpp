#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap(void)
{
	std::cout << "Call FragTrap Destructor" << std::endl;
}
FragTrap::FragTrap(const FragTrap &data): ClapTrap()
{
	std::cout << "Call FragTrap copy constructor " << std::endl;
	this->_name = data._name;
	this->_attack = data._attack;
	this->_hit = data._hit;
	this->_energy = data._energy;
}
FragTrap &FragTrap::operator=(const FragTrap &data)
{
	std::cout << "Call FragTrap Copy assignment operator" << std::endl;
	if(this != &data)
	{
		this->_name = data._name;
		this->_attack = data._attack;
		this->_hit = data._hit;
		this->_energy = data._energy;
	}
	return(*this);
}
FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attack = 30;
	this->_hit = 100;
	this->_energy = 100;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name  << " high five." << std::endl;
}
