#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"

int	main( void )
{
	Bureaucrat	worker("Alan", 10);
	AForm		Aform1("AForm1", 3, 3);
	AForm		Aform2("AForm2", 15, 15);

	std::cout << worker << std::endl << std::endl;
	std::cout << Aform1 << std::endl << std::endl;
	std::cout << Aform2 << std::endl << std::endl;

	worker.signForm(Aform1); std::cout << std::endl;
	worker.signForm(Aform2); std::cout << std::endl;

	std::cout << Aform1 << std::endl << std::endl;
	std::cout << Aform2 << std::endl << std::endl;

	return 0;
}