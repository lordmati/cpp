#include "Zombie.hpp"

int main (void)
{
	Zombie *player;
	player = newZombie("newzombie");
	player->announce();
	delete player;
	randomChump("randomchump");
}