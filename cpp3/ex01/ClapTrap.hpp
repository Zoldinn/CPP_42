#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

 #include <iostream>
 #include <string>

 class ClapTrap
 {
	public:
		ClapTrap( void );
		ClapTrap( std::string const name );
		ClapTrap( ClapTrap const & cpy );
		~ClapTrap( void );
		ClapTrap&		operator=( ClapTrap const & other );

		void			attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		unsigned int	getHP( void );

	protected:
		std::string const	_name;
		unsigned int		_health;
		unsigned int		_stamina;
		unsigned int		_damage;
 };

#endif