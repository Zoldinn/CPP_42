#ifndef DIAMONDTRAP_HPP
 #define DIAMONDTRAP_HPP

 #include "ScavTrap/ScavTrap.hpp"
 #include "FragTrap/FragTrap.hpp"
 
 class DiamondTrap : public ScavTrap, FragTrap
 {
	public:
		DiamondTrap( std::string const & name );
		DiamondTrap( DiamondTrap const & other );
		~DiamondTrap( void );
		DiamondTrap	&operator=( DiamondTrap const & other );

		void		whoAmI( void );
		using		ScavTrap::attack;
 
	private:
		DiamondTrap( void );
		std::string	_name;
		using		FragTrap::_health;
		using		ScavTrap::_stamina;
		using		FragTrap::_damage;

 };
 
#endif