#include "BitcoinExchange.hpp"

int	main( int ac, char **av ) 
{
	if ( ac != 2 )
	{
		std::cerr << "Error: Wrong argument count" << std::endl;
		return 1;
	}

	std::string	ti = av[1]; //? test if need a parsing or not (if .open handle on its own no need)
	
	BitcoinExchange	*btc;
	try 
	{
		btc = new BitcoinExchange( ti );
	}
	catch ( const std::fstream::failure& e ) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
		//? check if need to delete btc ?
		return -1;
	}
	catch (...)
	{
		std::cerr << "Error: Failed initialize class BitcoinExchange" << std::endl;
		//? check if need to delete btc ?
		return -1;
	}

	btc->solver();

	delete btc;
	return 0;
}