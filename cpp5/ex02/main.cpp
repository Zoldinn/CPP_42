#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	PresidentialPardonForm	pardonRequest("Toto"); // sign :25, exec :5
	RobotomyRequestForm		robotomyRequest("Bill"); // sign : 72, exec :45
	ShrubberyCreationForm	homeShrub("home"); // sign : 145, exec :137

	// Bureaucrat				*crashTest1 = 0;
	// Bureaucrat				*crashTest2 = 0;
	Bureaucrat				*mid = 0;
	Bureaucrat				*chef = 0;
	Bureaucrat				*slave = 0;

	try
	{
		// crashTest1 = new Bureaucrat("CrashTest1", -1);
		// crashTest2 = new Bureaucrat("CrashTest2", 200);
		mid = new Bureaucrat("mid", 50); // pardonRequest only
		chef = new Bureaucrat("chef", 1); // can sign, exec all forms
		slave = new Bureaucrat("Slave", 150); // cannot do anything
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

	std::cout << std::endl;
	chef->signForm(pardonRequest); // ok
	chef->executeForm(pardonRequest); // ok
	chef->signForm(robotomyRequest); // ok
	chef->executeForm(robotomyRequest); // ok
	chef->signForm(homeShrub); // ok
	chef->executeForm(homeShrub);std::cout << std::endl; // ok

	mid->signForm(pardonRequest); // fail
	mid->executeForm(pardonRequest); // fail
	mid->signForm(robotomyRequest); // ok
	mid->executeForm(robotomyRequest); // fail
	mid->signForm(homeShrub); // ok
	mid->executeForm(homeShrub);std::cout << std::endl; // ok

	slave->signForm(pardonRequest); // fail
	slave->executeForm(pardonRequest); // fail
	slave->signForm(robotomyRequest); // fail
	slave->executeForm(robotomyRequest); // fail
	slave->signForm(homeShrub); // fail
	slave->executeForm(homeShrub);std::cout << std::endl; // fail


	delete mid;
	delete chef;
	delete slave;
	return 0;
}