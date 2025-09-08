#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "target";
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecLvl() > executor.getGrade() || this->getSignLvl() > executor.getGrade())
		throw GradeTooHighException();
	if (this->getSign() == false)
		throw FormNotSignException();
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}