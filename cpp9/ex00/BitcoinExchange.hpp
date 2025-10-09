#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

#define PATH_DATA	"data.csv"
#define DATA		0
#define INPUT		1

class BitcoinExchange
{
	private:
											BitcoinExchange( void );
		std::fstream						_fs[2];
		std::map<std::string, float>		_dtb[2];
		std::map<std::string, std::string>	_error_dtb;
		void								_fill( std::map<std::string, float>& dtb,
												std::fstream& fs, std::string& fsName );

	public:
											BitcoinExchange( std::string& ti );
											BitcoinExchange( const BitcoinExchange& copy );
											~BitcoinExchange( void );
		BitcoinExchange&					operator=( const BitcoinExchange& other );

		void								solver( void ) const;
		class EWrongFormat : public std::exception 
		{
			public:
				const char*	what() const throw();
		};
		class EFailedOpen : public std::exception 
		{
			public:
				const char*	what() const throw();
		};
};
