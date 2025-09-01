#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP
 
 #include <iostream>
 #include <fstream>
 #include "AForm.hpp"

 class PresidentialPardonForm : public AForm 
 {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& cpy );
		~PresidentialPardonForm( void );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& other );

		void					execute( Bureaucrat const & executor ) const;
		
	private:
		int						_signLvl;
		int						_execLvl;
		std::string				_target;
		bool					_sign;
 };

#endif