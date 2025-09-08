#include "../headers/Intern.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

Intern::Intern( void ) {};
Intern::Intern( const Intern& copy ) {*this = copy;};
Intern::~Intern( void ) {};
Intern&		Intern::operator=( const Intern& other ) {(void)other; return *this;};

/*==================================================================================*/

const char*	Intern::UnknownException::what() const throw()
{
	return "Unknown form";
}

AForm*		Intern::makeForm( const std::string formName, const std::string target )
{
	std::string	names[3] = {"robotomy request",
				"presidential pardon",
				"shrubbery creation"};
	AForm*		arr[3] = {new RobotomyRequestForm(target),
				new PresidentialPardonForm(target),
				new ShrubberyCreationForm(target)};
				std::cout << std::endl;
	int			wanted = 4;

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
			wanted = i;
		else
			delete arr[i];
	}
	std::cout << std::endl;
	if (wanted == 4)
		throw UnknownException();
	std::cout << "Intern creates " << formName << std::endl;
	return arr[wanted];
}