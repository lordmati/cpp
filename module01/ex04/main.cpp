#include "replace.hpp"

int main (int argc,char **argv)
{
	if(argc != 4)
	{
		std::cerr << "Error: arguments incorrect" << "\n";
		return (1);
	}
	const char *fd = argv[1];
	size_t pos;
	std::string line;
	std::string save_fd;
	std::string aux = std::string(fd);
	std::string s1 = argv[2];
	if (s1.length() == 0)
	{
		std::cout << "Error: s1 is empty" << std::endl;
		return(1);
	}
	std::string s2 = argv[3];
	aux.append(".replace");
	std::ifstream openfd(fd);
	if (!openfd)
	{
		std::cerr << "Error: Openfd" << "\n";
		return (1);
	}
	std::ofstream new_file(aux.c_str());
	if (!new_file)
	{
		std::cerr << "Error: create new_file" << std::endl;
		return (1);
	}
	while(getline(openfd,line))
	{
		if(!save_fd.empty())
			save_fd.append("\n").append(line);
		else
			save_fd.append(line);
	}
	openfd.close();
	pos = save_fd.find(s1);
	if (pos == std::string::npos)
	{
		new_file << save_fd;
		new_file.close();
		return (0);
	}
	else
	{
		while (pos != std::string::npos)
		{
			save_fd = save_fd.substr(0,pos)
					+ s2
					+ save_fd.substr(pos + s1.length());
			pos = save_fd.find(s1,pos + s2.length());
		}
	}
	new_file << save_fd;
	new_file.close();
	return (0);
}

