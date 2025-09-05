#include "Form.hpp"
#include "Bureaucrat.hpp"

/**========================================================================
 *                    Constructors, destructor, overloads
 *========================================================================**/

Form::Form( void ) : _name("..."), _signLvl(1), _execLvl(1), _sign(false) {};

Form::Form( std::string name, int signLvl, int execLvl ) : _name(name),
	_signLvl(signLvl), _execLvl(execLvl), _sign(false)
{
	if (this->_signLvl < 1 || this->_execLvl < 1)
		throw GradeTooHighException();
	if (this->_signLvl > 150 || this->_execLvl > 150)
		throw GradeTooLowException();
}

Form::Form( const Form& cpy ) : _name(cpy._name),
	_signLvl(cpy._signLvl), _execLvl(cpy._execLvl), _sign(cpy._sign) {};

Form::~Form( void ) {};

Form&				Form::operator=( const Form& other ) {(void)other; return *this;};

std::ostream&		operator<<( std::ostream& os, const Form& toPrint )
{
	os << "Form :" << std::endl
		<< "- Name : " << toPrint.getName() << std::endl
		<< "- Sign grade required : " << toPrint.getSignLvl() << std::endl
		<< "- Exec grade required : " << toPrint.getExecLvl() << std::endl
		<< "- Sign : " << (toPrint.getSign() ? "Yes" : "No");
	return os;
}

/**========================================================================
 *                              Exceptions
 *========================================================================**/

const char*			Form::GradeTooHighException::what( void ) const throw()
{
	return "Form grade is too high";
}

const char*			Form::GradeTooLowException::what( void ) const throw()
{
	return "Form grade is too low";
}

/**========================================================================
 *                           Getters, setters
 *========================================================================**/

const std::string&	Form::getName( void ) const {return this->_name;};
const int&			Form::getSignLvl( void ) const {return this->_signLvl;};
const int&			Form::getExecLvl( void ) const {return this->_execLvl;};
const bool&			Form::getSign( void ) const {return this->_sign;};

void				Form::beSigned( Bureaucrat& signatory )
{
	if (signatory.getGrade() > this->_signLvl)
		throw Form::GradeTooHighException();
	this->_sign = true;
}
