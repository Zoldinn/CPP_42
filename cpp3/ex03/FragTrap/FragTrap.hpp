#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

 #include "../ClapTrap/ClapTrap.hpp"

 class FragTrap : public virtual ClapTrap
 {
	public:
		FragTrap( std::string const name );
		FragTrap( FragTrap const & cpy );
		~FragTrap( void );

		FragTrap&		operator=( FragTrap const & other );

		void			highFivesGuys(void);

	protected:
		FragTrap( void );
 };

#endif