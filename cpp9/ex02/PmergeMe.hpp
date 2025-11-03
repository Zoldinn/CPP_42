#pragma once 

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <exception>
#include <algorithm>
#include <ctime>

#include <vector>
#include <deque>

typedef struct s_pair { int a, b; } pair;

void	printVec( std::vector<int>& x );
void	printDeq( std::deque<int>& x );

class PmergeMe
{
	public:
							PmergeMe( char** av );
							PmergeMe( const PmergeMe& copy );
							~PmergeMe( void );
		PmergeMe&			operator=( const PmergeMe& other );

		std::vector<int>	vecFordJohnson( std::vector<int>& x );
		std::vector<pair>	vecFormPairs( std::vector<int>& v );

		std::deque<int>		deqFordJohnson( std::deque<int>& x );
		std::deque<pair>	deqFormPairs( std::deque<int>& d );
		
		void				solver( PmergeMe* s );

		std::vector<int>	vec;
		std::deque<int>		deq;

	private:
							PmergeMe( void );
};