#ifndef ANIMAL_HPP
 #define ANIMAL_HPP
 
 #include <iostream>

 class Animal
 {
	public:
		Animal( void );
		Animal( Animal const & other );
		~Animal( void );
		Animal	&operator=( Animal const & other );
 
	protected:
		std::string	_name;
 };
 
#endif