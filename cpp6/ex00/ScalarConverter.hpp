#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <iostream>
 #include <cstdlib>
 #include <cctype>
 #include <limits>

 class ScalarConverter
 {
	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		~ScalarConverter( void );
		ScalarConverter&	operator=( const ScalarConverter& other );

		static void			convert( std::string str );
 };

void	convertFromChar( char val );
void	convertFromInt( int val );
void	convertFromFloat( float val );
void	convertFromDouble( double val );


#endif