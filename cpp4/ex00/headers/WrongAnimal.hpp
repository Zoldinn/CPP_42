#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

 #include <iostream>
 
 class WrongAnimal
 {
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & other );
		virtual			~WrongAnimal( void );
		WrongAnimal&	operator=( WrongAnimal const & other );

		void			makeSound( void ) const; //not virtual to play animal sound
	
	protected:
		std::string		_type;
 };

#endif