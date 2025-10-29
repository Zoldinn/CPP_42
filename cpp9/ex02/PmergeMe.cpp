#include "PmergeMe.hpp"

/**========================================================================
 **                                 UTILS
 *========================================================================**/

bool	checkIntOverflow( std::string& str )
{
	std::istringstream	iss( str );
	unsigned long long	tmp;
	
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

PmergeMe&	PmergeMe::operator=( const PmergeMe& other )
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

void	vecMoveTo( std::vector<pair>& a, std::vector<pair>& b, size_t i )
{
	pair	tmp;

	tmp = a[i];
	for ( int k = i; k - 1 >= 0; k-- )
		a[k] = a[k - 1];
	a[0] = tmp;
	b.push_back( a.front() );
	a.erase( a.begin() );
}

std::vector<pair>	PmergeMe::VFormPairs( std::vector<int>& v )
{
	std::vector<pair>	res;

	for ( int i = 0; i + 1 < v.size(); i++ )
	{
		if ( v[i] <= v[i + 1] )
			res.push_back( pair{ v[i + 1], v[i] } );
		else
			res.push_back( pair{ v[i], v[i + 1] } );
	}
	return res;
}

std::vector<int>	jacobsthalNumbers( std::vector<int>& lowers )
{
	std::vector<int>			js, res;
	std::vector<int>::iterator	last;

	res.push_back( 1 );
	js.push_back( 1 ); js.push_back( 3 ); // initialize the suite

	last = js.end() - 1; // last element
	while ( *last < lowers.size() )
	{
		for ( int i = *last; i > *(last - 1); i-- )
			res.push_back( i );

		js.push_back( *last + (2 * *(last - 1) ) ); 

		last = js.end() - 1;
	}
	if ( res.size() < lowers.size() )
	{
		for ( int i = lowers.size(); i > *(last - 1); i-- )
			res.push_back( i );
	}
	return res;
}

std::vector<int>	PmergeMe::VFordJohnson( std::vector<int>& x )
{
	std::vector<pair>	pairs;
	std::vector<int>	bigs, lowers;


	if ( x.size() == 1 )
		return x;
	
	pairs = VFormPairs( x );
	for ( int i = 0; i < pairs.size(); i++ )
	{
		bigs.push_back( pairs[i].a );
		lowers.push_back( pairs[i].b );
	}

	x = VFordJohnson( bigs );
	// binary insertion with b's with JS
	for ( int i = 0; i < lowers.size(); i++ )
	{
		// calculer a partir de i quel index insérer binairement selon JS
		int k = // JS[i]
		// moveTo() lowers[ JS[i] ] to x (x qui contiendra que les big trié recur)
		// avec le binary insertion sort	
	}
	for ( )
}