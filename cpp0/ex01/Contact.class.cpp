#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";

	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::initContact(void)
{
	std::cout << ">First name : ";
	std::cin >> this->_firstName;

	std::cout << ">Last name : ";
	std::cin >> this->_lastName;

	std::cout << ">Nickname : ";
	std::cin >> this->_nickname;

	std::cout << ">Phone number : ";
	std::cin >> this->_phoneNumber;

	std::cout << ">Your darkest secret : ";
	std::cin >> this->_darkestSecret;

	return;
}

std::string	Contact::getInfo(std::string info) const
{
	if (info == "firstName")
		return (this->_firstName);
	else if (info == "lastName")
		return (this->_lastName);
	else if (info == "nickname")
		return (this->_nickname);
	else if (info == "phoneNumber")
		return (this->_phoneNumber);
	else if (info == "darkestSecret")
		return (this->_darkestSecret);
	return ("");
}
