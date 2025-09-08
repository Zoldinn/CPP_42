#ifndef INTERN_HPP
 #define INTERN_HPP

 #include <iostream>
 #include "AForm.hpp"

 class Intern
 {
	public:
		Intern( void );
		Intern( const Intern& copy );
		~Intern( void );
		Intern&	operator=( const Intern& other );

		AForm*	makeForm( const std::string formName, const std::string target );

		class UnknownException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
 };

#endif