#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "target";
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getExecLvl() > executor.getGrade() || this->getSignLvl() > executor.getGrade())
		throw GradeTooHighException();
	if (this->getSign() == false)
		throw FormNotSignException();

	std::fstream	fs;
	std::string		nameFile;

	nameFile = this->_target + "_shrubbery";
	fs.open(nameFile, std::fstream::out);
	if (fs.is_open())
	{
		fs << "			_-_";
		fs << "	/~~   ~~\\";
		fs << "/~~         ~~\\";
		fs << "{               }";
		fs << "\\  _-     -_  /";
		fs << "~  \\\\ //  ~";
		fs << "_- -   | | _- _";
		fs << "_ -  | |   -_";
		fs << "	// \\\\";
		fs.close();
	}
}