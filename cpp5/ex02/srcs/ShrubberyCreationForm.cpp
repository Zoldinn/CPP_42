#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	this->_signLvl = 145;
	this->_execLvl = 137;
	this->_target = "target";
	this->_sign = false;
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string& target )
{
	this->_signLvl = 145;
	this->_execLvl = 137;
	this->_target = target;
	this->_sign = false;
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
		this->_execLvl = other._execLvl;
		this->_signLvl = other._signLvl;
		this->_target = other._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		if (this->_execLvl > executor.getGrade() || this->_signLvl > executor.getGrade())
			throw AForm::GradeTooHighException();
		if (this->_sign == false)
			throw AForm::FormNotSignException();

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
	catch (const AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignException& e)
	{
		std::cout << e.what() << std::endl;
	}
}