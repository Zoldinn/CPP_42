#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;

	private:
		int		_nbContact;
		Contact	_book[8];
		void	_showContactList(void) const;
		void	_printFormated(std::string info) const;
};

#endif