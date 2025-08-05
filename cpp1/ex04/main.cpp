#include <iostream>
#include <fstream>
#include <string>

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
				if (line.compare(av[2]) == 0)
					newfs << av[3];
				else
					newfs << line;
				newfs << std::endl;
			}
			newfs.close();
		}
		oldfs.close();
	}
	return 0;
}
