#ifndef DOG_HPP
 #define DOG_HPP

 #include <iostream>
 #include "Animal.hpp"
 #include "Brain.hpp"
 
 class Dog : public Animal
 {
	public:
		Dog( void );
		Dog( Dog const & other );
		~Dog( void );
		Dog &operator=( Dog const & other );
 
		void	makeSound( void ) const;

	private:
		Brain*	brain;
 };
 
#endif