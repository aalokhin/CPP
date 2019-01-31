#include "AwesomePhonebook.hpp"

const std::string str_full("Phonebook is already full. You can use SEARCH or EXIT commands only");
const std::string ask_info("Enter ADD, SEARCH or EXIT command to create, use or exit your Phonebook");
const std::string error_input("Error on input: wrong command. Enter ADD, SEARCH or EXIT command to create, use or exit your Phonebook");
const std::string seach_str("Please enter the index of the relevant contact to see details");

void AwesomePhonebook::add()
{
	std::cout << "Enter first name" << std::endl;
	std::cin >> f_name;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter last name" << std::endl;
	std::cin >> l_name;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter nickname" << std::endl;
	std::cin >> n_name;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');


	std::cout << "Enter login" << std::endl;
	std::cin >> login;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter address" << std::endl;
	std::cin >> address;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter email" << std::endl;
	std::cin >> email;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');


	std::cout << "Enter phone" << std::endl;
	std::cin >> phone;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter birthday date" << std::endl;
	std::cin >> birthday;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Enter favourite meal" << std::endl;
	std::cin >> fav_meal;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');


	std::cout << "Enter underwear color" << std::endl;
	std::cin >> undercolor;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

	std::cout << "Finally! Enter the darkest secret" << std::endl;
	std::cin >> darkest_secret;
	if (std::cin.fail())
		exit (0);
	std::cin.ignore(100, '\n');

}

void AwesomePhonebook::print_one()
{
	std::cout << "First name: "<< f_name << std::endl;
    std::cout << "Last name: " << l_name << std::endl;
    std::cout << "Nickname: " << n_name << std::endl;
    std::cout << "Login: " << login << std::endl;
    std::cout << "Address: "<< address << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone number: "<< phone << std::endl;
    std::cout << "Birthday date: "<< birthday << std::endl;
    std::cout << "Favourite meal: "<< fav_meal << std::endl;
    std::cout << "Underwear color: "<< undercolor << std::endl;
    std::cout << "Darkest secret: "<< darkest_secret << std::endl;


}

void AwesomePhonebook::show_info()
{
	int i;
	char tmp[11];

	i = 0;
	while (i < 9)
	{
		tmp[i] = f_name[i];
		i++;
	}
	tmp[i++] = '.';
	tmp[i++] = 0;
	std::cout << std::setw (10);
  	std::cout << tmp;
  	std::cout << '|';

  	i = 0;
	while (i < 9)
	{
		tmp[i] = l_name[i];
		i++;
	}
	tmp[i++] = '.';
	tmp[i++] = 0;
	std::cout << std::setw (10);
  	std::cout << tmp;
  	std::cout << '|';

  	i = 0;
	while (i < 9)
	{
		tmp[i] = n_name[i];
		i++;
	}
	tmp[i++] = '.';
	tmp[i++] = 0;
	std::cout << std::setw (10);
  	std::cout << tmp;
  	std::cout << std::endl;

}
