#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <iostream>
 #include <string>
 #include <sstream>
 #include <cstdlib>
 #include <cctype>
 #include <limits>
 #include <iomanip>
 #include <cmath>

 class ScalarConverter
 {
	public:
		static void			convert( std::string str );

	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		~ScalarConverter( void );
		ScalarConverter&	operator=( const ScalarConverter& other );

 };

 void	convertFromChar( std::string str );
 void	convertFromInt( std::string str );
 void	convertFromFloat( std::string str );
 void	convertFromDouble( std::string str );

 typedef enum type {CHAR, INT, FLOAT, DOUBLE, ERROR} type;


#endif