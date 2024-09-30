#include "Harl.hpp"
int main (int argc, char **argv)
{
	Harl level;
	if (argc != 2)
	{
		std::cout << "Error arguments" << std::endl;
		return (1);
	}
	level.complain(argv[1]);
}