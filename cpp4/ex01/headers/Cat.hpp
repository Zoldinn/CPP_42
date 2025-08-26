#ifndef CAT_HPP
 #define CAT_HPP

 #include <iostream>
 #include "Animal.hpp"
 #include "Brain.hpp"
 
 class Cat : public Animal
 {
	public:
		Cat( void );
		Cat( Cat const & other );
		~Cat( void );
		Cat&	operator=( Cat const & other );
 
		void	makeSound( void ) const;

	private:
		Brain*	brain;
 };
 
#endif