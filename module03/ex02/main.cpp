#include "FragTrap.hpp"

int main (void)
{
	FragTrap Test("Nisman");
	Test.attack("Fort");
	Test.takeDamage(10);
	Test.beRepaired(10);
	Test.highFivesGuys();
}