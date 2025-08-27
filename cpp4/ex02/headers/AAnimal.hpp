#ifndef AANIMAL_HPP
 #define AANIMAL_HPP
 
 #include <iostream>

 class AAnimal
 {
	public:
		AAnimal( void );
		AAnimal( AAnimal const & other );
		virtual			~AAnimal( void );

		AAnimal&		operator=( AAnimal const & other );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
 
	protected:
		std::string		_type;
 };
 
#endif