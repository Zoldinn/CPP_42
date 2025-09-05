#include "headers/Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{

	PresidentialPardonForm	pardonRequest("Toto");
	RobotomyRequestForm		robotomyRequest("Bill");
	ShrubberyCreationForm	homeShrub("home");

	Bureaucrat	mid("Alan", 50);
	Bureaucrat	chef("Boubou", 1);
	Bureaucrat	slave("Slave", 150);
	Bureaucrat	crashTest1("CrashTest1", -1);
	Bureaucrat	crashTest2("CrashTest2", 200);

	mid.executeForm(pardonRequest);
	mid.executeForm(robotomyRequest);
	mid.executeForm(homeShrub);

		mid.executeForm(pardonRequest);
	mid.executeForm(robotomyRequest);
	mid.executeForm(homeShrub);

		mid.executeForm(pardonRequest);
	mid.executeForm(robotomyRequest);
	mid.executeForm(homeShrub);

		mid.executeForm(pardonRequest);
	mid.executeForm(robotomyRequest);
	mid.executeForm(homeShrub);

		mid.executeForm(pardonRequest);
	mid.executeForm(robotomyRequest);
	mid.executeForm(homeShrub);


	return 0;
}