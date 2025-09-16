#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <iostream>
 #include <cstdlib>
 #include <cctype>
 #include <limits>
 #include <iomanip>
 #include <cmath>

 class ScalarConverter
 {
	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		~ScalarConverter( void );
		ScalarConverter&	operator=( const ScalarConverter& other );

		static void			convert( std::string str );
 };

 void	convertFromChar( std::string str );
 void	convertFromInt( std::string str );
 void	convertFromFloat( std::string str );
 void	convertFromDouble( std::string str );


#endif