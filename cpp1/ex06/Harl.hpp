#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

typedef enum
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}	type;

class Harl
{
	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif