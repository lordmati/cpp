#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap Test("Nisman");
	Test.attack("Fort");
	Test.takeDamage(10);
	Test.beRepaired(10);
	Test.guardGate();
}