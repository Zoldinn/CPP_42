#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"

int main()
{
	Animal*	animals[4];

	std::cout << "====================" << std::endl;

	animals[0] = new Dog();
	std::cout << "-----" << std::endl;
	animals[1] = new Dog();

	std::cout << "====================" << std::endl;

	animals[2] = new Cat();
	std::cout << "-----" << std::endl;
	animals[3] = new Cat();

	std::cout << "====================" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << "-----" << std::endl;
	}

	return 0;
}