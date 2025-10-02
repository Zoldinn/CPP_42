#pragma once

#include <iostream>
#include <stack>
#include <list>

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
							MutantStack( void );
							MutantStack( const MutantStack& copy );
							~MutantStack( void );

		MutantStack&		operator=( const MutantStack& other );

		typedef typename	std::stack<T>::container_type::iterator	iterator;
		iterator			begin( void );
		iterator			end( void );
};

#include "MutantStack.tpp"
