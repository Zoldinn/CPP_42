#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _iContact(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add(void)
{
	if (++_iContact >= 8)
		_iContact = 0;
	this->_book[_iContact].setContact();
	return;
}

// SEARCH : affiche le contact demandé
// ◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
// 		first name, last name et nickname.
// ◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// 		par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
// 		de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
// 		un point (’.’).
// ◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher.
// 		Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// 		Sinon, affichez les informations du contact, une par ligne
void	PhoneBook::search(void) const
{
	int	who;

	for (int i = 0; i <= 8; i++)
	{
		if (this->_book[i].getInfo("first_name").empty() == false)
		{
			std::cout << std::right << std::setw(10) << i << "|";
			if (this->_book->getInfo("first_name").size() > 10)
				std::cout << std::right << std::setw(10) << this->_book->getInfo("first_name").substr(10) + '.' << "|";
			else
				std::cout << std::right << std::setw(10) << this->_book->getInfo("first_name") << "|";
			if (this->_book->getInfo("last_name").size() > 10)
				std::cout << std::right << std::setw(10) << this->_book->getInfo("last_name").substr(10) + '.' << "|";
			else
				std::cout << std::right << std::setw(10) << this->_book->getInfo("last_name") << "|";
			if (this->_book->getInfo("nickname").size() > 10)
				std::cout << std::right << std::setw(10) << this->_book->getInfo("nickname").substr(10) + '.' << "|";
			else
				std::cout << std::right << std::setw(10) << this->_book->getInfo("nickname") << "|";
			std::cout << std::endl;
		}
	}
	while (1)
	{
		std::cout << "Which contact do you want ? (Enter the index) : " << std::endl;
		std::cin >> who;
		if (who < 0 || who >= 8 || this->_book[who].getInfo("first_name").empty() == true)
			std::cout << "Wrong index" << std::endl;
		else
			break;
	}
	std::cout << this->_book[who].getInfo("first_name") << std::endl;
	std::cout << this->_book[who].getInfo("last_name") << std::endl;
	std::cout << this->_book[who].getInfo("nickname") << std::endl;
	std::cout << this->_book[who].getInfo("phone number") << std::endl;
	std::cout << this->_book[who].getInfo("darkest_secret") << std::endl;

	return;
}