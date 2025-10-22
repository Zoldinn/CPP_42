#include <iostream>
#include <vector>

std::vector<std::string>	split( std::string str, std::string sep )
{
	std::vector<std::string>	split;
	size_t						start, end;

	start = 0;
	end = 0;
	while ( start < str.size() )
	{
		start = str.find_first_not_of( sep, start );
		if ( start == std::string::npos )
			break;
		end = str.find_first_of( sep, start );
		if ( end == std::string::npos )
			end = str.size();
		split.push_back( str.substr( start, end - start) );
		start = end;
	}
	return split;
}

std::vector<int>	to_int( std::vector<std::string> split )
{
	std::vector<int>	res;

	for ( int i = 0; i < split.size(); i++ )
		res.push_back( std::atoi( split[i].c_str() ) );
	return res;
}

void	swap( int* a, int*b )
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print( std::vector<int>& tab )
{
	for ( int i = 0; i < tab.size(); i++ )
	{
		std::cout << tab[i];
		if ( i + 1 < tab.size() )
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void	insert_algorithm( std::vector<int>& tab )
{
	for ( int i = 1; i < tab.size(); i++ )
	{
		int j = i;
		while ( j > 0 && tab[j - 1] > tab[j] )
		{
			swap( &tab[j - 1], &tab[j] );
			print( tab );
			j = j - 1;
		}
	}
}

int	main( int ac, char** av )
{
	std::vector<int>	tab;

	if ( ac != 2 )
		return 1;
	tab = to_int( split(av[1], " ") );
	print( tab );

	insert_algorithm( tab );
	
	std::cout << " ========== res ========== " << std::endl;
	print( tab );

	return 0;
}
