#include "header.hpp"

Base::~Base( void ) {};

Base*	generate( void )
{
	std::srand( std::time(NULL) );
	switch ( std::rand() % 3 )
	{
		case 0:
			std::cout << "A generated !" << std::endl;
			return new A();
		case 1:
			std::cout << "B generated !" << std::endl;
			return new B();
		case 2:
			std::cout << "C generated !" << std::endl;
			return new C();

		default:
			std::cout << "Error at generation" << std::endl;
			return NULL;
	}
}

void	identify( Base* p )
{
	if ( !p )
		std::cout << "Error: NULL" << std::endl;
	else if ( dynamic_cast< A* >( p ) )
		std::cout << "A" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C" << std::endl;
	else
		std::cout << "Error: do not match" << std::endl;
}

void	identify( Base& p )
{
	try 
	{
		(void)dynamic_cast< A& >( p );
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {};

	try 
	{
		(void)dynamic_cast< B& >( p );
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {};

	try 
	{
		(void)dynamic_cast< C& >( p );
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {};

	std::cout << "Error: do not match" << std::endl;
}

int	main( void )
{
	Base*	base;

	base = generate();

	std::cout << "identifier using pointer :" << std::endl;
	identify(base);

	std::cout << "identifier using reference :" << std::endl;
	identify(*base);

	delete base;
	return 0;
}
