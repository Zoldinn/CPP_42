#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

 #include <iostream>
 #include <string>

 class ClapTrap
 {
	public:
		ClapTrap( std::string const name );
		ClapTrap( ClapTrap const & cpy );
		~ClapTrap( void );
		ClapTrap&		operator=( ClapTrap const & other );

		void			attack( const std::string& target );
		void			takeDamage( int amount );
		void			beRepaired( int amount );

		int	getHP( void );

	private:
		ClapTrap( void );
		std::string const	_name;
		int		_health;
		int		_stamina;
		int const	_damage;
 };

#endif