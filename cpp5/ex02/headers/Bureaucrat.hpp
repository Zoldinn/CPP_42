#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

 #include <iostream>
 #include <exception>

 class AForm;

 class Bureaucrat
 {
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( std::string name, int grade, int exec );
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat( void );
		Bureaucrat&			operator=( const Bureaucrat& other );

		const std::string&	getName( void ) const;
		int					getGrade( void ) const;
		void				upperGrade( void );
		void				lowerGrade( void );
		void				setGrade( int grade );
		void				signForm( AForm& form );
		void				executeForm( AForm const & form ) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what( void ) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what( void ) const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
		int					_exec;

 };

 std::ostream&	operator<<( std::ostream& os, const Bureaucrat& toPrint );

#endif