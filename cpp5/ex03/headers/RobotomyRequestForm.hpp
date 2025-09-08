#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP
 
 #include <iostream>
 #include <fstream>
 #include "AForm.hpp"

 class RobotomyRequestForm : public AForm
 {
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		~RobotomyRequestForm( void );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
 
		void					execute( Bureaucrat const & executor ) const;

	private:
		std::string				_target;
 };
 
#endif