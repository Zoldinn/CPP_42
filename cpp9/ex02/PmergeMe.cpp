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

