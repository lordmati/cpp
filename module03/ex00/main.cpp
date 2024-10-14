#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap Test("Javo");
	Test.attack("Cristina");
	Test.takeDamage(10);
	Test.beRepaired(10);
}