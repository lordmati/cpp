#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie Player(name);
	Player.announce();
}