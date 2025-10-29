#pragma once 

#include <iostream>
#include <sstream>
#include <limits>
#include <exception>
#include <algorithm>

#include <vector>
#include <list>

typedef struct s_pair { int a, b; } pair;

class PmergeMe
{
	public:
							PmergeMe( char** av );
							PmergeMe( const PmergeMe& copy );
							~PmergeMe( void );
		PmergeMe&			operator=( const PmergeMe& other );

		std::vector<int>&	getVec( void );
		std::vector<int>	vecFordJohnson( std::vector<int>& x );
		std::vector<pair>	vecFormPairs( std::vector<int>& v );

		void				lstFordJohnson( void );
		std::list<pair>		lstFormPairs( void );
		
		void				solver( void );

	private:
							PmergeMe( void );

		std::vector<int>	_vec;
		std::list<int>		_lst;
};