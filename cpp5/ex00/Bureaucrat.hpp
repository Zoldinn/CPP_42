#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

 #include <iostream>

 class Bureaucrat
 {
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);

		const std::string&	getName() const;
		int					getGrade() const;
		void				upperGrade();
		void				lowerGrade();
		void				setGrade(const int& grade);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

 };

 std::ostream&	operator<<(std::ostream os, const Bureaucrat& toPrint);

#endif