#include "Human.hpp"

int		main()
{
	Human bob;

	std::string victims[] = {"nation", "USA", "Ukraine", "fucking bastards", "children"};
	std::string attackers[] = {"intimidatingShout", "meleeAttack", "rangedAttack", "something that is not supposed to work", "", "123", "intimidatingShout"};

	size_t victims_amount = 0;



size_t attackers_amount = 0;


 	victims_amount = sizeof(victims)/sizeof(victims[0]);
	attackers_amount = sizeof(attackers)/sizeof(attackers[0]);
	system("echo \"\033[0;31m\"");

    size_t i = 0;
    size_t j = 0;
    while (j < attackers_amount)
    {
    	i = 0;
	    while (i < victims_amount)
	    {
	    	bob.action(attackers[j], victims[i]);
	    	i++;
	    }
	    j++;
	}

	system("echo \"\033[0m\"");

	return 0;
}