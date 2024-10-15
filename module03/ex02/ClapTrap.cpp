#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_attack = 0;
	this->_hit = 10;
	this->_energy = 10;
	this->_name = "NULL";
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "Call ClapTrap Destructor" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &data)
{
	std::cout << "Call ClapTrap copy constructor " << std::endl;
	this->_name = data._name;
	this->_attack = data._attack;
	this->_hit = data._hit;
	this->_energy = data._energy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &data)
{
	std::cout << "Call ClapTrap Copy assignment operator" << std::endl;
	if(this != &data)
	{
		this->_name = data._name;
		this->_attack = data._attack;
		this->_hit = data._hit;
		this->_energy = data._energy;
	}
	return(*this);
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attack = 0;
	this->_hit = 10;
	this->_energy = 10;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
	this->_hit = this->_hit - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " does not have energy points." << std::endl;
	else if (this->_hit <= 0)
		std::cout << "ClapTrap " << this->_name << " does not have hit points." << std::endl;
	else
	{
		this->_energy = this->_energy - 1;
		this->_hit = this->_hit + amount;
		std::cout << "ClapTrap " << this->_name << " be repaired " << amount << std::endl; 
	}
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit <= 0 && this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " does not have a hit points and energy points." << std::endl;
	else if (this->_hit <= 0)
		std::cout << "ClapTrap " << this->_name << " does not have a hit points." << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " does not have a energy points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy = this->_energy - 1;
	}
}