#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/Intern.hpp"

int	main( void )
{
	Bureaucrat	executor("Bureaucrat", 1);
	Intern		intern;
	AForm*		form;

	try
	{
		form = intern.makeForm("robotomy request", "Bender");
		// form = intern.makeForm("presidential pardon", "Zack");
		// form = intern.makeForm("shrubbery creation", "Castel");
		// form = intern.makeForm("Holidays request", "Fool");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	executor.signForm(*form);
	executor.executeForm(*form);
	
	delete form;
	return 0;
}