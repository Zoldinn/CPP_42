#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

 #include "../ClapTrap/ClapTrap.hpp"
 
 class ScavTrap : public virtual ClapTrap
 {
	public:
		ScavTrap( std::string const name );
		ScavTrap( ScavTrap const & cpy );
		~ScavTrap( void );
		ScavTrap&		operator=( ScavTrap const & other );

		void			attack( const std::string& target );
		void			guardGate( void );

	protected:
		ScavTrap( void );

 };
 
#endif