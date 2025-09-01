#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
{
	this->_signLvl = 25;
	this->_execLvl = 5;
	this->_target = "target";
	this->_sign = false;
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string& target )
{
	this->_signLvl = 25;
	this->_execLvl = 5;
	this->_target = target;
	this->_sign = false;
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
	{
		this->_execLvl = other._execLvl;
		this->_signLvl = other._signLvl;
		this->_target = other._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		if (this->_execLvl > executor.getGrade() || this->_signLvl > executor.getGrade())
			throw AForm::GradeTooHighException();
		if (this->_sign == false)
			throw AForm::FormNotSignException();

		std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignException& e)
	{
		std::cout << e.what() << std::endl;
	}
}