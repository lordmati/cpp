#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				argv[i][j] = std::toupper(argv[i][j]);
				std::cout << argv[i][j];
				j++;
			}
			i++;
		}
	}
	std::cout << "\n";
    return 0;
}