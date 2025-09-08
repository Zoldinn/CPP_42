#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	worker;
	int			tests[4] = {151, 0, 20, 3};

	for (int i = 0; i < 4; i++)
	{
		try
		{
			worker = new Bureaucrat("worker", tests[i]);
			std::cout << *worker << std::endl;
			delete worker;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}