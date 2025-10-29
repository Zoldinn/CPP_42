#include "PmergeMe.hpp"

/**========================================================================
 **                                 UTILS
 *========================================================================**/

bool	checkIntOverflow( std::string& str )
{
	std::istringstream	iss( str );
	long long int		tmp;
	
	iss >> tmp;
	if ( iss.fail() )
		return false;
	if ( tmp > std::numeric_limits<int>::max() )
		return false;
	return true;
}

/**========================================================================
 **                           CONSTRUCTORS, ...
 *========================================================================**/

PmergeMe::PmergeMe( void ) {}; // private / should not be used

PmergeMe::PmergeMe( char** av )
{
	std::string	str;

	for ( int i = 0; av[i]; i++ )
	{
		str = av[i];
		if ( checkIntOverflow(str) == false )
			throw std::exception();
		_vec.push_back( std::atoi( str.c_str() ) );
		_lst.push_back( std::atoi( str.c_str() ) );
	}
}

PmergeMe::PmergeMe( const PmergeMe& copy ) { *this = copy; };

PmergeMe::~PmergeMe( void ) {};

PmergeMe&			PmergeMe::operator=( const PmergeMe& other )
{
	if ( this != &other )
	{
		this->_vec = other._vec;
		this->_lst = other._lst;
	}
	return *this;
}

/**========================================================================
 **           VECTOR | MERGE INSERTION SORT / FORD-JOHNSON ALGO
 *========================================================================**/

std::vector<pair>	PmergeMe::vecFormPairs( std::vector<int>& v )
{
	std::vector<pair>	res;

	for ( size_t i = 0; i + 1 < v.size(); i++ )
	{
		pair p;
		if ( v[i] <= v[i + 1] )
		{
			p.a = v[i + 1]; p.b = v[i];
			res.push_back( p );
		}
		else
		{
			p.a = v[i]; p.b = v[i + 1];
			res.push_back( p );
		}
	}
	return res;
}



std::vector<int>	jacobsthalNumbers( std::vector<int>& pend )
{
	std::vector<int>			js, res;
	std::vector<int>::iterator	last;

	res.push_back( 1 );
	js.push_back( 1 ); js.push_back( 3 ); // initialize the suite

	last = js.end() - 1; // last element
	while ( *last < static_cast<int>( pend.size() ) )
	{
		for ( int i = *last; i > *(last - 1); i-- )
			res.push_back( i );

		js.push_back( *last + (2 * *(last - 1) ) ); 

		last = js.end() - 1;
	}
	if ( res.size() < pend.size() )
	{
		for ( int i = static_cast<int>( pend.size() ); i > *(last - 1); i-- )
			res.push_back( i );
	}
	return res;
}



void				insert( std::vector<int>& x, size_t insertPos, size_t toInsert )
{
	int	tmp;

	x.push_back( toInsert );
	tmp = toInsert;
	for ( size_t k = x.size() - 1; k >= insertPos + 1; k-- )
		x[k] = x[k - 1];
	x[insertPos] = tmp;
}

void				binary_insert( std::vector<int>& x, int toInsert )
{
	std::vector<int>::iterator	insertIt;
	size_t						insertPos;

	insertIt  = std::lower_bound( x.begin(), x.end(), toInsert );
	insertPos = std::distance( x.begin(), insertIt );
	insert( x, insertPos, toInsert );
}

std::vector<int>	PmergeMe::vecFordJohnson( std::vector<int>& x )
{
	std::vector<pair>	pairs;
	std::vector<int>	main, pend, js;

	if ( x.size() == 1 )
		return x;
	
	pairs = vecFormPairs( x );
	for ( size_t i = 0; i < pairs.size(); i++ )
	{
		main.push_back( pairs[i].a );
		pend.push_back( pairs[i].b );
	}
	x = vecFordJohnson( main );

	js = jacobsthalNumbers( pend );
	for ( size_t i = 0; i < js.size(); i++ )
		binary_insert( main, pend[ js[i] ] );
	if ( x.size() % 2 != 0 )
		binary_insert( main, x.back() );

	return main;
}

std::vector<int>&	PmergeMe::getVec( void )
{
	return _vec;
}