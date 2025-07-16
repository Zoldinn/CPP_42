#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	this->_firstName = "default";
	this->_lastName = "default";
	this->_nickname = "default";
	this->_phoneNumber = "default";
	this->_darkestSecret = "default";

	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::setContact(void)
{
	std::cout << ">First name : ";
	std::cin >> this->_firstName;

	std::cout << ">Last name : ";
	std::cin >> this->_lastName;

	std::cout << ">Nickname : ";
	std::cin >> this->_nickname;

	std::cout << ">Phone number : ";
	std::cin >> this->_phoneNumber;

	std::cout << ">Darkest secret : ";
	std::cin >> this->_darkestSecret;

	return;
}

std::string	Contact::getInfo(std::string info) const
{
	if (info == "first_name" && this->_firstName != "default")
		return (this->_firstName);
	else
		return ("");
	if (info == "last_name" && this->_lastName != "default")
		return (this->_lastName);
	else
		return ("");
	if (info == "nickname" && this->_nickname != "default")
		return (this->_nickname);
	else
		return ("");
	if (info == "phone_number" && this->_phoneNumber != "default")
		return (this->_phoneNumber);
	else
		return ("");
	if (info == "darkest_secret" && this->_darkestSecret != "default")
		return (this->_darkestSecret);
	else
		return ("");
	return ("");
}
