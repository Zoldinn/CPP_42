#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon 
{
	public:
		Weapon( void );
		~Weapon( void );

		const std::string&	getType( void ) const;
		void				setType( std::string type );

	private:
		std::string	_type;
}

#endif