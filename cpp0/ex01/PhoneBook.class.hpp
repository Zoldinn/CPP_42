#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		static int	getNbContact(void);

	private:
		static int	_nbContact;
		Contact		_contact[8];
};

#endif