#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		add(void);
		void		search(void);
		void		exit(void);

	private:
		std::map<std::string, Contact>	_contact;
};

#endif