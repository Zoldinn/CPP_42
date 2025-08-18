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
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		std::string		getName( void ) const;
		unsigned int	getHealth( void ) const;
		unsigned int	getStamina( void ) const;
		int const		getDamage( void ) const;
		void			setHealth( unsigned int newAmount );
		void			setStamina( unsigned int newAmount );

	private:
		std::string const	_name;
		unsigned int		_health;
		unsigned int		_stamina;
		unsigned int const	_damage;
 };

 std::ostream&	operator<<( std::ostream& os, ClapTrap const & obj );

#endif