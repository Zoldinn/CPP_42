#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	Bureaucrat	worker("Alan", 10);
	Form		form1("Form1", 3, 3);
	Form		form2("Form2", 15, 15);

	std::cout << worker << std::endl << std::endl;
	std::cout << form1 << std::endl << std::endl;
	std::cout << form2 << std::endl << std::endl;

	worker.signForm(form1); std::cout << std::endl;
	worker.signForm(form2); std::cout << std::endl;

	std::cout << form1 << std::endl << std::endl;
	std::cout << form2 << std::endl << std::endl;

	return 0;
}