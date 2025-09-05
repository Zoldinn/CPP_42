#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	PresidentialPardonForm	pardonRequest("Toto");
	RobotomyRequestForm		robotomyRequest("Bill");
	ShrubberyCreationForm	homeShrub("home");

	// Bureaucrat				*crashTest1 = 0;
	// Bureaucrat				*crashTest2 = 0;
	Bureaucrat				*mid = 0;
	Bureaucrat				*chef = 0;
	Bureaucrat				*slave = 0;

	try
	{
		// crashTest1 = new Bureaucrat("CrashTest1", -1);
		// crashTest2 = new Bureaucrat("CrashTest2", 200);
		mid = new Bureaucrat("Alan", 50);
		chef = new Bureaucrat("Boubou", 1);
		slave = new Bureaucrat("Slave", 150);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		// delete crashTest1;
		// delete crashTest2;
		delete mid;
		delete chef;
		delete slave;
		return 1;
	}

	mid->executeForm(pardonRequest);
	mid->executeForm(robotomyRequest);
	mid->executeForm(homeShrub);

	chef->executeForm(pardonRequest);
	chef->executeForm(robotomyRequest);
	chef->executeForm(homeShrub);

	slave->executeForm(pardonRequest);
	slave->executeForm(robotomyRequest);
	slave->executeForm(homeShrub);

	return 0;
}