#include <iostream>
#include "phonebook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook created" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook deleted" << std::endl;
	return;
}

int	PhoneBook::getNbContact(void)
{
	return (PhoneBook::_nbContact);
}