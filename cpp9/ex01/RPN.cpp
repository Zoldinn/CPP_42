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
		this->_stack = other._stack;
	}
	return *this;
}

/**========================================================================
 *                                  Solver
 *========================================================================**/

int				do_op( char op, int nb1, int nb2 )
{
	if ( (nb1 == 0 || nb2 == 0) && op == '/' )
		throw std::exception();
	switch ( op )
	{
		case '+':
			return nb1 + nb2;
		case '-':
			return nb1 - nb2;
		case '*':
			return nb1 * nb2;
		case '/':
			return nb1 / nb2;
		default:
			throw std::exception();
	}
}

void			RPN::solver( void )
{
	std::string*	tab;
	size_t			nbw;
	int				nb1, nb2;

	tab = split( _expr, " " );
	if ( !tab )
		throw std::exception();
	nbw = count_word(_expr, " ");

	for ( size_t i = 0; i < nbw; i++ )
	{
		if ( tab[i].size() == 1 && isdigit(tab[i][0]) )
			_stack.push( atoi( tab[i].c_str() ) );
		else if ( tab[i].size() == 1 && tab[i].find_first_of("+-*/") != std::string::npos
			&& _stack.size() >= 2 )
		{
			nb2 = _stack.top(); _stack.pop();
			nb1 = _stack.top(); _stack.pop();
			try { _stack.push( do_op(tab[i][0], nb1, nb2) ); }
			catch ( const std::exception& e ) { delete [] tab; throw std::exception(); }
		}
		else
		{
			delete [] tab;
			throw std::exception();
		}
	}

	delete [] tab;
	if ( _stack.size() != 1 )
		throw std::exception();

	std::cout << _stack.top() << std::endl;
}
