#ifndef DOG_HPP
 #define DOG_HPP

 #include <iostream>
 #include "AAnimal.hpp"
 #include "Brain.hpp"
 
 class Dog : public AAnimal
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