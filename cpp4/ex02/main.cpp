#include "../headers/AAnimal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"

int main()
{
	// AAnimal	a; // Cannot be instanciate
	AAnimal*	dog = new Dog();

	dog->makeSound();
	// a.makeSound(); // pure virtual function

	delete dog;
	return 0;
}