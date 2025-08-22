#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

 #include <iostream>
 #include <string>

 class ClapTrap
 {
	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & cpy );
		~ClapTrap( void );
		ClapTrap&		operator=( ClapTrap const & other );

		void			attack( const std::string& target );
		void			takeDamage( int amount );
		void			beRepaired( int amount );

		int	getHP( void );

	protected:
		ClapTrap( void );
		std::string			_name;
		int					_health;
		int					_stamina;
		int					_damage;
 };

#endif