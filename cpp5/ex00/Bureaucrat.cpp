#include "Bureaucrat.hpp"

/**========================================================================
 *                    Constructors, destructor, overloads
 *========================================================================**/
Bureaucrat::Bureaucrat() {};
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {};
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {this->_grade = other._grade;}
Bureaucrat::~Bureaucrat() {};

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& other) {return *this;};
std::ostream&		operator<<(std::ostream os, const Bureaucrat& toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << "." << std::endl;
	return os;
}

/**========================================================================
 *                           Getters, setters
 *========================================================================**/

int					Bureaucrat::getGrade() const {return this->_grade;};
const std::string&	Bureaucrat::getName() const {return this->_name;};
void				Bureaucrat::upperGrade() {this->_grade++;};
void				Bureaucrat::lowerGrade() {this->_grade--;};
void				Bureaucrat::setGrade(const int& grade) {this->_grade = grade;};