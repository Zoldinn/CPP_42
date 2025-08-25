#ifndef DOG_HPP
 #define DOG_HPP

 #include <iostream>
 
 class Dog
 {
	public:
		Dog( void );
		Dog( Dog const & other );
		~Dog( void );
		Dog &operator=( Dog const & other );
 
	private:
		// attributes
 };
 
#endif