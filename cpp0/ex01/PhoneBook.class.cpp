#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : nbContact(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add(void)
{
	if (nbContact + 1 < 8) // Add the new contact to the next;
	{
		nbContact += 1;
		this->_book[nbContact].initContact();
	}
	else
	{
		for (int i = 7; i > 0; i--)
			this->_book[i] = this->_book[i - 1];
		this->_book[0].initContact();
	}
	return;
}

void	PhoneBook::search(void)
{
	return;
}