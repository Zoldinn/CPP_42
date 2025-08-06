#include <iostream>
#include <fstream>
#include <string>

void	search_and_replace(std::string& line, std::string s1, std::string s2)
{
	std::size_t	found = 0;
	
	found = line.find(s1);
	while (found != std::string::npos)
	{
		line.erase(found, s1.size());
		line.insert(found, s2);
		found = line.find(s1, found + s2.size());
	}
}

int	main( int ac, char **av )
{
	std::fstream	oldfs;
	std::fstream	newfs;
	std::string		line;
	std::string		newFileName;

	if (ac != 4)
		return 1;
	oldfs.open(av[1], std::fstream::in);
	if (oldfs.is_open())
	{
		newFileName = av[1];
		newFileName.append(".replace");
		newfs.open(newFileName.c_str(), std::fstream::out);
		if (newfs.is_open())
		{
			while (getline(oldfs, line))
			{
				search_and_replace(line, av[2], av[3]);
				newfs << line;
				newfs << std::endl;
			}
			newfs.close();
		}
		oldfs.close();
	}
	return 0;
}
