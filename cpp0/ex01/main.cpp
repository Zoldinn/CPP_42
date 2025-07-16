#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	order;

	std::cout << "You can :" << std::endl;
	std::cout << "'ADD' a new contact to the phone book" << std::endl;
	std::cout << "'SEARCH' a contact in the phone book" << std::endl;
	std::cout << "'EXIT' the Phonebook" << std::endl;

	while (1)
	{
		std::cin >> order;
		if (order == "EXIT")
			return (0);
		else if (order == "ADD")
			book.add();
		else if (order == "SEARCH")
			book.search();
	}
	return (0);
}