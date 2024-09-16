#include "Zombie.hpp"

void Zombie::setname(std::string name)
{
	this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *z;
	z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setname(name);
	return(z);
}

