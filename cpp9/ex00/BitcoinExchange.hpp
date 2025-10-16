#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <map>

#define PATH_DATA	"data.csv"
#define YEAR		0
#define MONTH		1
#define DAY			2
#define SIZE_T_ERR	static_cast<size_t>(-1)

class BitcoinExchange
{
	private:
		std::fstream						_fs_data;
		std::fstream						_fs_input;
		std::map<std::string, float>		_data_dtb;
		void								_fill_data_dtb( std::string& dataPath );

	public:
											BitcoinExchange( void );
											BitcoinExchange( const BitcoinExchange& copy );
											~BitcoinExchange( void );
		BitcoinExchange&					operator=( const BitcoinExchange& other );

		void								solver( std::string& inputFile );

		class EWrongFormat : public std::exception 
		{
			public:
				const char*	what() const throw();
		};
		class EFailedOpen : public std::exception 
		{
			private:
				std::string&	_msg;
			public:
								EFailedOpen( std::string& msg );
				const char*		what() const throw();
		};
};
