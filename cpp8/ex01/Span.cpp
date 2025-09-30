#include "Span.hpp"

/**========================================================================
*                           Constructors, destructor, overload
***========================================================================**/

Span::Span( void ) : _maxSize( 0 ) {};
Span::Span( unsigned int n ) : _maxSize( n ) {};
Span::Span( const Span& copy ) : _maxSize( 0 ) { *this = copy; };
Span::~Span( void ) {};

Span&	Span::operator=( const Span& other )
{
	if ( this != &other )
	{
		this->vec = other.vec;
		this->_maxSize = other._maxSize;
	}
	return *this;
}

/**========================================================================
*                           Required features
***========================================================================**/

void	Span::addNumber( int n )
{
	if ( vec.size() > _maxSize )
		throw std::exception();
	vec.push_back( n );
}