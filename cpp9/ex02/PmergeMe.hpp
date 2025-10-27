#pragma once 

#include <iostream>
#include <sstream>
#include <limits>
#include <exception>

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

		void				vecMergeInsertSort( void );
		std::vector<pair>	vecDivideIntoPairs( void );

		void				lstMergeInsertSort( void );
		std::list<pair>		lstDivideIntoPairs( void );
		
		void				solver( void );

	private:
		PmergeMe( void );
		std::vector<int>	_vec;
		std::list<int>		_lst;
};