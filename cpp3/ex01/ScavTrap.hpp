#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

 #include "ClapTrap.hpp"
 
 class ScavTrap : public ClapTrap
 {
	public:
		ScavTrap( std::string const name );
		ScavTrap( ScavTrap const & cpy );
		~ScavTrap( void );
		ScavTrap&		operator=( ScavTrap const & other );

		void	guardGate( void );

	private:

 };
 
#endif