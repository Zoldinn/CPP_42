#include <iostream>
#include "Contact.hpp"

/**========================================================================
 *                           Constructor/Destructor
 *========================================================================**/

Contact::Contact(void) : isCreated(false)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

/*==============================================================*/

void	Contact::setContact(void)
{
	std::cout << ">First name \t: ";
	std::cin >> this->_firstName;

	std::cout << ">Last name \t: ";
	std::cin >> this->_lastName;

	std::cout << ">Nickname \t: ";
	std::cin >> this->_nickname;

	std::cout << ">Phone number \t: ";
	std::cin >> this->_phoneNumber;

	std::cout << ">Darkest secret\t: ";
	std::cin >> this->_darkestSecret;

	std::cout << "Contact added !" << std::endl << std::endl;
	this->isCreated = true;
}

/*==============================================================*/

std::string	Contact::getInfo(std::string info) const
{
	if (info == "first_name" && this->isCreated == true)
		return (this->_firstName);
	if (info == "last_name" && this->isCreated == true)
		return (this->_lastName);
	if (info == "nickname" && this->isCreated == true)
		return (this->_nickname);
	if (info == "phone_number" && this->isCreated == true)
		return (this->_phoneNumber);
	if (info == "darkest_secret" && this->isCreated == true)
		return (this->_darkestSecret);
	return ("");
}

/*==============================================================*/

void	Contact::printInfo() const
{
	if (this->isCreated == false)
	{
		std::cout << std::endl << "No informations" << std::endl;
		return ;
	}
	std::cout << "First name \t| " << this->_firstName << std::endl;
	std::cout << "Last name \t| " << this->_lastName << std::endl;
	std::cout << "Nickname \t| " << this->_nickname << std::endl;
	std::cout << "Phone number \t| " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret\t| " << this->_darkestSecret << std::endl << std::endl;
}
