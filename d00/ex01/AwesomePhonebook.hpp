
#ifndef AWESOME_PHONEBOOK_HPP
#define AWESOME_PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

extern const std::string str_full;
extern const std::string ask_info;
extern const std::string error_input;
extern const std::string seach_str;

class AwesomePhonebook {
  public:
  	AwesomePhonebook() {};
  	~AwesomePhonebook() {};
  	std::string f_name, l_name, n_name, login, address, email, phone;
  	std::string birthday, fav_meal, undercolor, darkest_secret;

  	void	add();
  	void	show_info();
  	void 	print_one();
};

#endif
