#include "BitcoinExchange.hpp"

int	main( int ac, char **av ) 
{
	if ( ac != 2 )
	{
		std::cerr << "Error: Wrong argument count" << std::endl;
		return 1;
	}

	std::string	inputFile = av[1];
	
	BitcoinExchange	*btc;
	try 
	{
		btc = new BitcoinExchange();
		btc->solver( inputFile );
	}
	catch ( const BitcoinExchange::EFailedOpen& e ) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}
	catch (...)
	{
		std::cerr << "Error: Failed initialize class BitcoinExchange" << std::endl;
		return -1;
	}


	delete btc;
	return 0;
}