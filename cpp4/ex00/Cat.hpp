#ifndef CAT_HPP
 #define CAT_HPP

 #include <iostream>
 
 class Cat
 {
	public:
		Cat( void );
		Cat( Cat const & other );
		~Cat( void );
		Cat &operator=( Cat const & other );
 
	private:
		// attributes
 };
 
#endif