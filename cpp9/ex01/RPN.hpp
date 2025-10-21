#pragma once

#include <iostream>
#include <iomanip>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
							RPN( std::string expr );
							RPN( const RPN& copy );
							~RPN( void );

		RPN&				operator=( const RPN& other );
		void				solver( void );
	private:
							RPN( void );
		std::string			_expr;
		std::stack<int>		_stack;

};

// nb operator must be nb factors - 1
// 