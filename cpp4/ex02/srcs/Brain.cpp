#include "../headers/Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain\t created" << std::endl;
}

Brain::Brain( Brain const & other )
{
	*this = other;
	std::cout << "Brain\t copied" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain\t destroyed" << std::endl;
}

Brain&	Brain::operator=( Brain const & other )
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}