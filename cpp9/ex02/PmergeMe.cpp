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
	if ( tmp < 0 || tmp > std::numeric_limits<int>::max() )
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

	for ( int i = 1; av[i]; i++ )
	{
		str = av[i];
		if ( checkIntOverflow(str) == false )
			throw std::exception();
		vec.push_back( std::atoi( str.c_str() ) );
		deq.push_back( std::atoi( str.c_str() ) );
	}
}

PmergeMe::PmergeMe( const PmergeMe& copy ) { *this = copy; };

PmergeMe::~PmergeMe( void ) {};

PmergeMe&	PmergeMe::operator=( const PmergeMe& other )
{
	if ( this != &other )
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return *this;
}

/**========================================================================
 **           VECTOR | MERGE INSERTION SORT / FORD-JOHNSON ALGO
 *========================================================================**/

std::vector<pair>	PmergeMe::vecFormPairs( std::vector<int>& v )
{
	std::vector<pair>	res;

	for ( size_t i = 0; i + 1 < v.size(); i += 2 )
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
		for ( int i = *last; i > *(last - 1); i-- ) // start from the upper bound interval
			res.push_back( i );                     // and add the rest of the interval

		js.push_back( *last + (2 * *(last - 1) ) ); // calcul the new upper bound (number from JS)

		last = js.end() - 1;
	}
	if ( res.size() < pend.size() ) // add the rest of the interval greater than the last JS bound 
	{
		for ( int i = static_cast<int>( pend.size() ); i > *(last - 1); i-- )
			res.push_back( i );
	}
	return res;
}

void	binary_insert( std::vector<int>& x, int toInsert )
{
	std::vector<int>::iterator	insertIt;
	size_t						insertPos, tmp;

	insertIt  = std::lower_bound( x.begin(), x.end(), toInsert );
	insertPos = std::distance( x.begin(), insertIt );
	x.push_back( toInsert );
	tmp = toInsert;
	for ( size_t k = x.size() - 1; k >= insertPos + 1; k-- )
		x[k] = x[k - 1];
	x[insertPos] = tmp;
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

	main = vecFordJohnson( main );

	js = jacobsthalNumbers( pend );
	for ( size_t i = 0; i < pend.size(); i++ )
		binary_insert( main, pend[ js[i] - 1 ] ); // -1 because js numbers start at 1
	if ( x.size() % 2 != 0 ) // insert the singleton
		binary_insert( main, x.back() );

	return main;
}

/**========================================================================
 **           DEQUE | MERGE INSERTION SORT / FORD-JOHNSON ALGO
 *========================================================================**/

std::deque<pair>	PmergeMe::deqFormPairs( std::deque<int>& d )
{
	std::deque<pair>	res;

	for ( size_t i = 0; i + 1 < d.size(); i += 2 )
	{
		pair	p;
		if ( d[i] <= d[i + 1] )
		{
			p.a = d[i + 1]; p.b = d[i];
			res.push_back( p );
		}
		else
		{
			p.a = d[i]; p.b = d[i + 1];
			res.push_back( p );
		}
	}
	return res;
}


std::deque<int>	jacobsthalNumbers( std::deque<int>& pend )
{
	std::deque<int>				js, res;
	std::deque<int>::iterator	last;

	res.push_back( 1 );
	js.push_back( 1 ); js.push_back( 3 ); // initialize the suite

	last = js.end() - 1; // last element
	while ( *last < static_cast<int>( pend.size() ) )
	{
		for ( int i = *last; i > *(last - 1); i-- ) // start from the upper bound interval
			res.push_back( i );                     // and add the rest of the interval

		js.push_back( *last + (2 * *(last - 1) ) ); // calcul the new upper bound (number from JS)

		last = js.end() - 1;
	}
	if ( res.size() < pend.size() ) // add the rest of the interval greater than the last JS bound 
	{
		for ( int i = static_cast<int>( pend.size() ); i > *(last - 1); i-- )
			res.push_back( i );
	}
	return res;
}

void	binary_insert( std::deque<int>& x, int toInsert )
{
	std::deque<int>::iterator	insertIt;
	size_t						insertPos, tmp;

	insertIt  = std::lower_bound( x.begin(), x.end(), toInsert );
	insertPos = std::distance( x.begin(), insertIt );
	x.push_back( toInsert );
	tmp = toInsert;
	for ( size_t k = x.size() - 1; k >= insertPos + 1; k-- )
		x[k] = x[k - 1];
	x[insertPos] = tmp;
}

std::deque<int>	PmergeMe::deqFordJohnson( std::deque<int>& x )
{
	std::deque<pair>	pairs;
	std::deque<int>		main, pend, js;

	if ( x.size() == 1 )
		return x;
	
	pairs = deqFormPairs( x );
	for ( size_t i = 0; i < pairs.size(); i++ )
	{
		main.push_back( pairs[i].a );
		pend.push_back( pairs[i].b );
	}

	main = deqFordJohnson( main );

	js = jacobsthalNumbers( pend );
	for ( size_t i = 0; i < pend.size(); i++ )
		binary_insert( main, pend[ js[i] - 1 ] ); // -1 because js numbers start at 1
	if ( x.size() % 2 != 0 ) // insert the singleton
		binary_insert( main, x.back() );

	return main;
}

/**========================================================================
 **                                   SOLVER
 *========================================================================**/

void	PmergeMe::solver( PmergeMe* s )
{

	std::clock_t	tv[2], td[2];

	std::cout << "Before : "; printVec( s->vec );

	tv[0] = std::clock();
	s->vec = s->vecFordJohnson( s->vec );
	tv[1] = std::clock();

	std::cout << "After  : "; printVec( s->vec );

	std::cout << "Time to process a range of " << s->vec.size()
			  << " elements with std::vector : "
			  << static_cast<double>( tv[1] - tv[0] ) / CLOCKS_PER_SEC << " s" << std::endl;

	td[0] = std::clock();
	s->deq = s->deqFordJohnson( s->deq );
	td[1] = std::clock();

	std::cout << "Time to process a range of " << s->deq.size()
			  << " elements with std::deque  : "
			  << static_cast<double>( td[1] - td[0] ) / CLOCKS_PER_SEC << " s" << std::endl;
}