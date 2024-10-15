#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "Call ScavTrap Destructor" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &data): ClapTrap()
{
	std::cout << "Call ScavTrap copy constructor " << std::endl;
	this->_name = data._name;
	this->_attack = data._attack;
	this->_hit = data._hit;
	this->_energy = data._energy;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &data)
{
	std::cout << "Call ScavTrap Copy assignment operator" << std::endl;
	if(this != &data)
	{
		this->_name = data._name;
		this->_attack = data._attack;
		this->_hit = data._hit;
		this->_energy = data._energy;
	}
	return(*this);
}
ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attack = 20;
	this->_hit = 100;
	this->_energy = 50;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}