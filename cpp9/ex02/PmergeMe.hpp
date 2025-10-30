#pragma once 

#include <iostream>
#include <sstream>
#include <limits>
#include <exception>
#include <algorithm>

#include <vector>
#include <list>

typedef struct s_pair { int a, b; } pair;

void	printVec( std::vector<int>& x );

class PmergeMe
{
	public:
							PmergeMe( char** av );
							PmergeMe( const PmergeMe& copy );
							~PmergeMe( void );
		PmergeMe&			operator=( const PmergeMe& other );

		std::vector<int>	vecFordJohnson( std::vector<int>& x );
		std::vector<pair>	vecFormPairs( std::vector<int>& v );

		void				lstFordJohnson( void );
		std::list<pair>		lstFormPairs( void );
		
		void				solver( void );

		std::vector<int>	vec;
		std::list<int>		lst;

	private:
							PmergeMe( void );
};