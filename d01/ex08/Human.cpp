#include <iostream>
#include "Human.hpp"

Human::Human(){};
Human::~Human(){};

void Human::meleeAttack(std::string const & target)
{
  std::cout << target << " is under melee attack" << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
  std::cout << target << " is under range attack" << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
  std::cout << target << " is under attack by intimidatingShout" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	void 		(Human::*functptr[])(std::string const &) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout} ;
	std::string arr_s[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	size_t i;

	i = 0;
	size_t arr_len;
	arr_len = sizeof(arr_s)/sizeof(arr_s[0]);

	while(i < arr_len)
	{
		if (action_name == arr_s[i])
			(this->*functptr[i])(target);
		
		i++;
	}
}
