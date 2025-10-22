#include "header.hpp"

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

void	print_vi( std::vector<int>& tab )
{
	for ( int i = 0; i < tab.size(); i++ )
	{
		std::cout << tab[i];
		if ( i + 1 < tab.size() )
			std::cout << ", ";
	}
	std::cout << std::endl;
}

std::vector<std::string>	vsplit( std::string str, std::string sep )
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

size_t			count_word( const std::string& str, const std::string& sep )
{
	size_t	pos   = 0;
	size_t	count = 0;

	while ( pos < str.size() )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		count += 1;
		pos = str.find_first_of( sep, pos );
	}
	return count;
}

std::string*	split( const std::string& str, const std::string& sep )
{
	size_t			i      = 0;
	size_t			pos    = 0;
	size_t			end	   = 0;
	size_t			nbWord = 0;
	std::string*	split  = NULL;

	nbWord = count_word(str, sep);
	if ( nbWord == 0 )
		return NULL;
	split = new std::string[ nbWord ];
	while ( pos < str.size() && i < nbWord )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		end = str.find_first_of(sep, pos);
		if ( end == std::string::npos )
			end = str.size();
		split[i++] = str.substr( pos, end - pos );
		pos = end;
	}
	return split;
}
