#include "Zombie.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Zombie *player;
	player = newZombie("newzombie");
	player->announce();
	delete player;
	randomChump("randomchump");
}