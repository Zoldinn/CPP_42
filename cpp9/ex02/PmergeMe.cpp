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

std::vector<int>	JacobsthalNumbers( std::vector<int>& lowers )
{
	std::vector<int>	js;
	int					k; // to find js(k) < lowers.size()

	js[0] = 0; js[1] = 1; js[2] = 1;
	for ( int i = 2; js[i] < lowers.size(); i++ )
		js.push_back( js[i - 1] + (2 * js[i - 2]) );
	
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
}