#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

/**========================================================================
 *!                           Constructor/Destructor
 *========================================================================**/

PhoneBook::PhoneBook(void) : _nbContact(0)
{
	return;
}

/////////////////////////////////////////////////////////////////////////////

PhoneBook::~PhoneBook(void)
{
	return;
}

/**========================================================================
 *!                           Utils
 *========================================================================**/

void	PhoneBook::_printFormated(std::string info) const
{
	if (info.size() > 10)
		std::cout << std::right << std::setw(10) << info.substr(10) + '.' << "|";
	else
		std::cout << std::right << std::setw(10) << info << "|";
}

/////////////////////////////////////////////////////////////////////////////

void	PhoneBook::_showContactList(void) const
{
	for (int i = 0; i <= this->_nbContact; i++)
	{
		if (this->_book[i].isCreated == true)
		{
			std::cout << std::right << std::setw(10) << i << "|";
			this->_printFormated(this->_book[i].getInfo("first_name"));
			this->_printFormated(this->_book[i].getInfo("last_name"));
			this->_printFormated(this->_book[i].getInfo("nickname"));
			std::cout << std::endl;
		}
		else
		{
			std::cout << "prout" << std::endl;
			break;
		}
	}
}

/**========================================================================
 *!                           Mandatory functions
 *========================================================================**/

void	PhoneBook::search(void) const
{
	std::string	who;
	int			index;

	this->_showContactList();

	if (this->_nbContact > 0)
	{
		std::cout << "Which contact do you want ? (Enter the index) : " << std::endl;
		std::cin >> who;
		if (who[0] >= '0' && who[0] <= '9' && who[1] == '\0')
		{
			index = who[0] - '0';
			if (index >= 0 && index < 8 && this->_book[index].isCreated == true)
				this->_book[index].printInfo();
		}
		else
			std::cout << "Wrong index" << std::endl;
	}
	else
		std::cout << "There's no contact" << std::endl;
	return;
}

/////////////////////////////////////////////////////////////////////////////

void	PhoneBook::add(void)
{
	this->_nbContact += 1;
	this->_book[(this->_nbContact % 8) - 1].setContact();
}

// EXIT() is in the main.cpp, no need to be member of the phonebook class
