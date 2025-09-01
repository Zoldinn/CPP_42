#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"

/**========================================================================
 *                    Constructors, destructor, overloads
 *========================================================================**/

AForm::AForm( void ) : _name("..."), _signLvl(1), _execLvl(1), _sign(false) {};

AForm::AForm( std::string name, int signLvl, int execLvl ) : _name(name),
	_signLvl(signLvl), _execLvl(execLvl), _sign(false) {};

AForm::AForm( const AForm& cpy ) : _name(cpy._name),
	_signLvl(cpy._signLvl), _execLvl(cpy._execLvl), _sign(cpy._sign) {};

AForm::~AForm( void ) {};

AForm&				AForm::operator=( const AForm& other ) {(void)other; return *this;};

std::ostream&		operator<<( std::ostream& os, const AForm& toPrint )
{
	os << "AForm :" << std::endl
		<< "- Name : " << toPrint.getName() << std::endl
		<< "- Sign grade required : " << toPrint.getSignLvl() << std::endl
		<< "- Exec grade required : " << toPrint.getExecLvl() << std::endl
		<< "- Sign : " << (toPrint.getSign() ? "Yes" : "No");
	return os;
}

/**========================================================================
 *                              Exceptions
 *========================================================================**/

const char*			AForm::GradeTooHighException::what( void ) const throw()
{
	return "Form grade is too high";
}

const char*			AForm::GradeTooLowException::what( void ) const throw()
{
	return "Form grade is too low";
}

const char*			AForm::FormNotSignException::what( void ) const throw()
{
	return "Form is not signed";
}

/**========================================================================
 *                           Getters, setters
 *========================================================================**/

const std::string&	AForm::getName( void ) const {return this->_name;};
const int&			AForm::getSignLvl( void ) const {return this->_signLvl;};
const int&			AForm::getExecLvl( void ) const {return this->_execLvl;};
const bool&			AForm::getSign( void ) const {return this->_sign;};

void				AForm::beSigned( Bureaucrat& signatory )
{
	if (signatory.getGrade() > this->_signLvl)
		throw AForm::GradeTooHighException();
	this->_sign = true;
}
