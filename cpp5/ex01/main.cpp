#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	Bureaucrat*	worker = 0;
	Form*		form1 = 0;
	Form*		form2 = 0;

	try
	{
		worker = new Bureaucrat("Alan", 10);
		form1 = new Form("Form1", 3, 3);
		form2 = new Form("Form2", 15, 15);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete worker;
		delete form1;
		delete form2;
		return 1;
	}

	std::cout << *worker << std::endl << std::endl;
	std::cout << *form1 << std::endl << std::endl;
	std::cout << *form2 << std::endl << std::endl;

	worker->signForm(*form1); std::cout << std::endl;
	worker->signForm(*form2); std::cout << std::endl;

	std::cout << *form1 << std::endl << std::endl;
	std::cout << *form2 << std::endl << std::endl;

	delete worker;
	delete form1;
	delete form2;
	return 0;
}