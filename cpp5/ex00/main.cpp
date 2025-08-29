#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	worker("Alan");
	int			tests[4] = {151, 0, 20, 3};

	for (int i = 0; i < 4; i++)
	{
		try
		{
			worker.setGrade(tests[i]);
			std::cout << worker << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}