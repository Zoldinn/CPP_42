#ifndef FORM_HPP
 #define FORM_HPP

 #include <iostream>
 #include <exception>

 class Bureaucrat;

 class Form
 {
	public:
		Form( std::string name, int signLvl, int execLvl );
		Form( const Form& cpy );
		~Form( void );
		Form&				operator=( const Form& other );
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what( void ) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what( void ) const throw();
		};
	
		const std::string&	getName( void ) const;
		const int&			getSignLvl( void ) const;
		const int&			getExecLvl( void ) const;
		const bool&			getSign( void ) const;
		void				beSigned( Bureaucrat& signatory );
		
	private:
		Form( void );
		const std::string	_name;
		const int			_signLvl;
		const int			_execLvl;
		bool				_sign;
 };

 std::ostream&				operator<<( std::ostream& os, const Form& toPrint );

#endif