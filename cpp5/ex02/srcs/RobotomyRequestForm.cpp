#include "../headers/Bureaucrat.hpp"
#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
{
	this->_signLvl = 72;
	this->_execLvl = 45;
	this->_target = "target";
	this->_sign = false;
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string& target )
{
	this->_signLvl = 72;
	this->_execLvl = 45;
	this->_target = target;
	this->_sign = false;
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
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
		this->_execLvl = other._execLvl;
		this->_signLvl = other._signLvl;
		this->_target = other._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		if (this->_execLvl > executor.getGrade() || this->_signLvl > executor.getGrade())
			throw AForm::GradeTooHighException();
		if (this->_sign == false)
			throw AForm::FormNotSignException();

		std::cout << "Make drilling noises" << std::endl;
		std::cout << this->_target << "have been robotomized successfully 50% of the time"
			<< std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "Robotomization failed..." << std::endl;
	}
	catch (const AForm::FormNotSignException& e)
	{
		std::cout << e.what() << std::endl;
	}
}