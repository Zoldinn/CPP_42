#include "RPN.hpp"

/**========================================================================
 *                                   Utils
 *========================================================================**/

size_t			count_word( const std::string& str, const std::string& sep )
{
	size_t	pos   = 0;
	size_t	count = 0;

	while ( pos < str.size() )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		count += 1;
		pos = str.find_first_of( sep, pos );
	}
	return count;
}

std::string*	split( const std::string& str, const std::string& sep )
{
	size_t			i      = 0;
	size_t			pos    = 0;
	size_t			end	   = 0;
	size_t			nbWord = 0;
	std::string*	split  = NULL;

	nbWord = count_word(str, sep);
	if ( nbWord == 0 )
		return NULL;
	split = new std::string[ nbWord ];
	while ( pos < str.size() && i < nbWord )
	{
		pos = str.find_first_not_of( sep, pos );
		if ( pos == std::string::npos )
			break;
		end = str.find_first_of(sep, pos);
		if ( end == std::string::npos )
			end = str.size();
		split[i++] = str.substr( pos, end - pos );
		pos = end;
	}
	return split;
}

/**========================================================================
 *                           Constructors, ...
 *========================================================================**/

RPN::RPN( void ) {}; // not usable

RPN::RPN( std::string expr ) { _expr = expr; };

RPN::RPN( const RPN& copy ) { *this = copy; };

RPN::~RPN( void ) {};

RPN&			RPN::operator=( const RPN& other )
{
	if ( this != &other )
	{
		this->_expr = other._expr;
		this->_digit_stack = other._digit_stack;
		this->_oper_stack = other._oper_stack;
	}
	return *this;
}

/**========================================================================
 *                                  Solver
 *========================================================================**/

bool			RPN::_fill_stacks( void )
{
	std::string*	splited_expr;

	splited_expr = split( _expr, " " );
	if ( !splited_expr )
		return false;

	for ( size_t i = 0; i < count_word(_expr, " "); i++ )
	{
		size_t size = splited_expr[i].size();

		if ( size == 1 && isdigit(splited_expr[i][0]) )
			_digit_stack.push( atoi( splited_expr[i].c_str() ) );
		else if ( size == 1 && splited_expr[i].find_first_of("+-*/") != std::string::npos )
			_oper_stack.push( splited_expr[i][0] );
		else
		{
			delete [] splited_expr;
			return false;
		}
	}

	delete [] splited_expr;
	return true;
}

void			RPN::solver( void )
{
	int		nb1, nb2;
	char	op;

	if ( _fill_stacks() == false || _oper_stack.size() != _digit_stack.size() - 1 )
		throw std::exception();

	while ( _digit_stack.size() > 1 )
	{
		nb1 = _digit_stack.top(); _digit_stack.pop();
		nb2 = _digit_stack.top(); _digit_stack.pop();
		op  = _oper_stack.top();  _oper_stack.pop();

		if ( (nb1 == 0 || nb2 == 0) && op == '/' )
			throw std::exception();

		switch ( op )
		{
			case '+':
				_digit_stack.push( nb1 + nb2 ); break;
			case '-':
				_digit_stack.push( nb1 - nb2 ); break;
			case '*':
				_digit_stack.push( nb1 * nb2 ); break;
			case '/':
				_digit_stack.push( nb1 / nb2 ); break;
		}
	}
	std::cout << _digit_stack.top() << std::endl;
}
