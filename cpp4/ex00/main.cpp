#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"

int main()
{
	const Animal* meta	= new Animal();
	const Animal* dog	= new Dog();
	const Animal* cat	= new Cat();

	std::cout << "======================" << std::endl;

	// meta (animal) don't have type (see subject)
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "======================" << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	std::cout << "======================" << std::endl;

	const WrongAnimal*	wrongMeta	= new WrongAnimal();
	const WrongAnimal*	wrongCat	= new WrongCat();

	std::cout << "======================" << std::endl;

	std::cout << "WrongAnimal :\t";
	wrongMeta->makeSound();

	std::cout << "WrongCat    :\t";
	wrongCat->makeSound();

	std::cout << "======================" << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongCat;
	return 0;
}