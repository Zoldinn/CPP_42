#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange( std::string inputFile );
		BitcoinExchange( const BitcoinExchange& copy );
		~BitcoinExchange( void );
		BitcoinExchange&				operator=( const BitcoinExchange& other );

		void							solver( void ) const;

	private:
		BitcoinExchange( void );
		std::fstream					_fs_tp; // file stream time/price
		std::fstream					_fs_ti; // file stream time/input
		std::map<std::string, float>	_dtb_tp; // database time/price
		std::map<std::string, float>	_dtb_ti; // database time/input
		void							_fill( std::map<std::string, float> dtb, std::fstream fs ); // to fill a dtb
};
