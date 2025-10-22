#include "header.hpp"

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