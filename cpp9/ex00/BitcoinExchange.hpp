#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& copy );
		~BitcoinExchange( void );

		BitcoinExchange&				operator=( const BitcoinExchange& other );
		std::fstream					fs;

	private:
		std::map<std::string, float>	_dtb;
};
