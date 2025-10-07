#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

#define PATH_TP	"./data.csv"

class BitcoinExchange
{
	private:
		BitcoinExchange( void );
		std::fstream					_fs_tp;  // file stream time/price
		std::fstream					_fs_ti;  // file stream time/input
		std::map<std::string, float>	_dtb_tp; // database time/price
		std::map<std::string, float>	_dtb_ti; // database time/input
		void							_fill( std::map<std::string, float>& dtb, std::fstream& fs, std::string& fsName );

	public:
		BitcoinExchange( std::string& ti );
		BitcoinExchange( const BitcoinExchange& copy );
		~BitcoinExchange( void );
		BitcoinExchange&				operator=( const BitcoinExchange& other );

		void							solver( void ) const;
		class EWrongFormat : public std::exception 
		{
			public:
				const char*	what() const throw();
		};
};
