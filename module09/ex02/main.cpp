#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if (argc > 3001 || argc < 2)
	{
		std::cout << "Error" << std::endl;
		return(-1);
	}
	if(!checkArgv(argv))
		return (1);
	makeVector(argv,argc);
}