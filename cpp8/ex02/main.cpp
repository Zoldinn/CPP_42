#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int>	mstack;

	mstack.push(5);		std::cout << "mstack.push(5)"	<< std::endl;
	mstack.push(17);	std::cout << "mstack.push(17)"	<< std::endl << std::endl;

	std::cout << "mstack.top() = " << mstack.top()		<< std::endl << std::endl;

	mstack.pop();		std::cout << "mstack.pop()"		<< std::endl << std::endl;

	std::cout << "mstack.size() = " << mstack.size()	<< std::endl;
	std::cout << "mstack.top() = " << mstack.top()		<< std::endl << std::endl;

	mstack.push(3);		std::cout << "mstack.push(3)"	<< std::endl;
	mstack.push(5);		std::cout << "mstack.push(5)"	<< std::endl;
	mstack.push(737);	std::cout << "mstack.push(737)"	<< std::endl;
	mstack.push(0);		std::cout << "mstack.push(0)"	<< std::endl << std::endl;

	std::cout << "mstack.top() = " << mstack.top()		<< std::endl << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it;
		if ( it + 1 != ite )
			std::cout << ", ";
		++it;
	}
	std::cout << std::endl;

	return 0;
}
