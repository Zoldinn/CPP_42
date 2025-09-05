#ifndef AFORM_HPP
 #define AFORM_HPP

 #include <iostream>
 #include <exception>

 class Bureaucrat;

 class AForm
 {
	public:
		AForm( void );
		AForm( std::string name, int signLvl, int execLvl );
		AForm( const AForm& cpy );
		virtual				~AForm( void );
		AForm&				operator=( const AForm& other );
	
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
		class FormNotSignException : public std::exception
		{
			public:
				const char*	what( void ) const throw();
		};
	
		const std::string&	getName( void ) const;
		const int&			getSignLvl( void ) const;
		const int&			getExecLvl( void ) const;
		const bool&			getSign( void ) const;
		void				beSigned( Bureaucrat& signatory );
		virtual void		execute( Bureaucrat const & executor ) const = 0;
		
	private:
		const std::string	_name;
		const int			_signLvl;
		const int			_execLvl;
		bool				_sign;
 };

 std::ostream&		operator<<( std::ostream& os, const AForm& toPrint );

#endif