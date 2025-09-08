#include "../headers/Bureaucrat.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "target";
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecLvl() < executor.getGrade() || this->getSignLvl() < executor.getGrade())
		throw GradeTooHighException();
	if (this->getSign() == false)
		throw FormNotSignException();
	std::cout << "*** Drilling noises ***" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " have been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " have not been robotomized" << std::endl;
}