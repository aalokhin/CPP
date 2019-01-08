# include <iostream>
# include <string>
# include <iomanip>
# include "AwesomePhonebook.hpp"

using namespace std;

int 		check_if_correct(std::string str)
{
	if (str != "ADD" && str != "SEARCH" && str != "EXIT")
		return (0);
	return (1);
}


void show_all(AwesomePhonebook *phonebook, int contacts_nbr)
{
  int i;

  i = 0;
  std::cout << std::setw (10);
  std::cout << "Index";
  std::cout << '|';
  std::cout << std::setw (10);
  std::cout << "First name";
  std::cout << '|';
  std::cout << std::setw (10);
  std::cout << "Last name";
  std::cout << '|';
  std::cout << std::setw (10);
  std::cout << "Nickname" << std::endl;
  while (i < contacts_nbr)
  {
    std::cout << std::setw (10);
    std::cout << i;
    std::cout << '|';
    phonebook[i].show_info();
    i++;
  }
}

int			main(void)
{
	AwesomePhonebook phonebook[8];
	std::string command;
	int contacts_nbr;
	int index;

	contacts_nbr = 0;
	while (command != "EXIT")
	{
		std::cout << ask_info << std::endl;
		std::cin >> command;
		if (std::cin.fail())
			exit (0);
		if (contacts_nbr == 8 && command == "ADD")
			std::cout << str_full << std::endl;
		else
		{
			if (check_if_correct(command) == 0)
			{
				std::cout << error_input << std::endl;
				continue ;
			}
			if (command == "SEARCH")
			{
				show_all(phonebook, contacts_nbr);
				std::cout << seach_str << std::endl;
				std::cin >> index;
				if (std::cin.fail())
  					exit (0);
  				if (index >= 0 && index < contacts_nbr)
  				{
  					std::cout << "Index: "<< index << std::endl;
  					phonebook[index].print_one(); //prints one
  				}
  				else
  					std::cout << "Incorrect index number!" << std::endl;
  				continue ;
				//not sure
			}
			if (contacts_nbr < 8 && command == "ADD")
			{
				phonebook[contacts_nbr].add(); //some function that creates a contact
				contacts_nbr++;
			}

		}

	}
	//std::cout << ask_info << std::endl;
	//std::cout << str_full << std::endl;
}
