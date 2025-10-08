#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

#define PATH_TP	"data.csv"

#define TP 0 // time/price
#define TI 1 // time/input

class BitcoinExchange
{
	private:
										BitcoinExchange( void );
		std::fstream					_fs[2];
		std::map<std::string, float>	_dtb[2];
		void							_fill( std::map<std::string, float>& dtb, std::fstream& fs,
											std::string& fsName );

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
