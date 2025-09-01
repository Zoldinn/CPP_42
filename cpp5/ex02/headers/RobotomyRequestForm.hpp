#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP
 
 #include <iostream>
 #include <fstream>
 #include "AForm.hpp"

 class RobotomyRequestForm : public AForm
 {
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		~RobotomyRequestForm( void );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
 
		void					execute( Bureaucrat const & executor ) const;

	private:
		int						_signLvl;
		int						_execLvl;
		std::string				_target;
		bool					_sign;
 };
 
#endif