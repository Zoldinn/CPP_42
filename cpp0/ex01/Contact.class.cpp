#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

std::string	Contact::getInfo(std::string info)
{
	return (this->_infos[info]);
}