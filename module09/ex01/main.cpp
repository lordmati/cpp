#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error arguments" << std::endl;
		return(-1);
	}
	makeStack(argv[1]);
}