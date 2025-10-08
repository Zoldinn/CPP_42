#include "BitcoinExchange.hpp"

int	main( int ac, char **av ) 
{
	if ( ac != 2 )
	{
		std::cerr << "Error: Wrong argument count" << std::endl;
		return 1;
	}

	std::string	ti = av[1];
	
	BitcoinExchange	*btc;
	try 
	{
		btc = new BitcoinExchange( ti );
	}
	catch ( const std::fstream::failure& e ) 
	{
		std::cerr << "Error: open() failed" << std::endl;
		return -1;
	}
	catch (...)
	{
		std::cerr << "Error: Failed initialize class BitcoinExchange" << std::endl;
		return -1;
	}

	btc->solver();

	delete btc;
	return 0;
}