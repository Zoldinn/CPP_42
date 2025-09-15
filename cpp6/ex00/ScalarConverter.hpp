#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <iostream>
 #include <cstdlib>
 #include <cctype>
 #include <limits>

 #define INFF	std::numeric_limits<float>::infinity()
 #define INF	std::numeric_limits<double>::infinity()
 #define NANF	std::numeric_limits<float>::quiet_NaN()
 #define NAN	std::numeric_limits<double>::quiet_NaN()

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