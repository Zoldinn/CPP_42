#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "RobotomyRequestForm.hpp"

/**========================================================================
 *                    Constructors, destructor, overloads
 *========================================================================**/

 Bureaucrat::Bureaucrat( void ) : _name("..."), _grade(150) {};
Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150) {};

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name) {this->_grade = other._grade;}
Bureaucrat::~Bureaucrat( void ) {};

Bureaucrat&			Bureaucrat::operator=( const Bureaucrat& other ) {(void)other;return *this;};
std::ostream&		operator<<( std::ostream& os, const Bureaucrat& toPrint )
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << ".";
	return os;
}

/**========================================================================
 *                           Getters, setters
 *========================================================================**/

int					Bureaucrat::getGrade( void ) const {return this->_grade;};
const std::string&	Bureaucrat::getName( void ) const {return this->_name;};

void				Bureaucrat::upperGrade( void ) // Go to 1
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this;
}

void				Bureaucrat::lowerGrade( void ) // Go to 150
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::setGrade( int grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

/**========================================================================
 *                              Exceptions
 *========================================================================**/

const char*			Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Grade too high ! It cannot be more than 1...";
}

const char*			Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Grade too low ! It cannot be less than 150...";
}

void				Bureaucrat::signForm( AForm& AForm )
{
	try
	{
		AForm.beSigned( *this );
		std::cout << this->_name << " signed " << AForm.getName() << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << this->_name << " couldn’t sign " << AForm.getName()
			<< " because : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn’t sign " << AForm.getName()
			<< " because : " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm( AForm const & form ) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->_name << " " << e.what() << std::endl;
	}
}