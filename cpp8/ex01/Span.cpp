#include "Span.hpp"

/**========================================================================
*                    Constructors, destructor, overload
***========================================================================**/

Span::Span( void ) : _maxSize( 0 ) {};
Span::Span( unsigned int n ) : _maxSize( n ) {};
Span::Span( const Span& copy ) : _maxSize( 0 ) { *this = copy; };
Span::~Span( void ) {};

Span&	Span::operator=( const Span& other )
{
	if ( this != &other )
	{
		this->_vec = other._vec;
		this->_maxSize = other._maxSize;
	}
	return *this;
}

/**========================================================================
*                           	Exception
***========================================================================**/

const char*	Span::EFull::what( void ) const throw()
{
	return "full";
}


const char*	Span::EEmpty::what( void ) const throw()
{
	return "empty";
}


/**========================================================================
*                                   Util
***========================================================================**/

void	Span::printVec( void )
{
	try 
	{
		if ( _vec.empty() )
			throw Span::EEmpty();
		for ( std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++ )
		{
			std::cout << *it;
			if ( it + 1 != _vec.end() )
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
	catch ( const :: Span::EEmpty& e )
	{
		std::cout << e.what() << std::endl;
	}
}

/**========================================================================
*                           Required features
***========================================================================**/

void	Span::addNumber( int n )
{
	try 
	{
		if ( _vec.size() >= _maxSize )
			throw Span::EFull();
		_vec.push_back( n );
	}
	catch ( const Span::EFull& e )
	{
		std::cout << e.what() << std::endl;
	}
}


int		Span::shortestSpan( void )
{
	std::vector<int>			copy, diff;
	std::vector<int>::iterator	res;

	if ( _vec.empty() || _vec.size() == 1 )
		throw Span::EEmpty();

	copy = _vec;
	std::sort( copy.begin(), copy.end() );
	for ( std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++ )
	{
		if ( it + 1 != copy.end() )
			diff.push_back(abs( *it - *(it + 1) ));
	}
	res = std::min_element( diff.begin(), diff.end() );
	return *res;
}


int		Span::longestSpan( void )
{
	std::vector<int>::iterator	min, max;

	if ( _vec.empty() || _vec.size() == 1 )
		throw Span::EEmpty();

	min = std::min_element( _vec.begin(), _vec.end() );
	max = std::max_element( _vec.begin(), _vec.end() );
	return *max - *min;
}
