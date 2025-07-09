#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <map>
# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		
		std::string	getInfo(std::string info);

	private:
		std::map<std::string, std::string>	_infos;

};

#endif