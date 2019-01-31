#include <iostream>
#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	this->level = 1;
	this->dead = false;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 100;
	this->max_energy_points = 100;
	this->melee_damage = 30;
	this->range_damage = 20;
	this->armor_dam_red = 5;
	std::cout << "ScavTrap Default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	Name = name;
	this->level = 1;
	this->dead = false;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;

	this->melee_damage = 20;
	this->range_damage = 15;
	this->armor_dam_red = 3;
	std::cout << "ScavTrap Name constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap()
{
  std::cout << "ScavTrap Copy constructor." << std::endl;
  *this = copy;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap Destructor" << std::endl;
  return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & obj)
{
  if (this != &obj)
  {
	this->level = obj.level;
	this->dead = obj.dead;

	this->hit_points = obj.hit_points;
	this->max_hit_points = obj.max_hit_points;
	this->energy_points = obj.energy_points;
	this->max_energy_points = obj.max_energy_points;

	this->melee_damage = obj.melee_damage;
	this->range_damage = obj.range_damage;
	this->armor_dam_red = obj.armor_dam_red;
	this->Name = obj.Name;
  }
  return (*this);
}

/************************************************* SCAV TRAP FUNCS *************************************************/


void 			ScavTrap::Challenge1()
{
	int choice = get_Rand_Int(2);

	std::cout << "truth or dare?\n";

	
	if (choice == 1) 
	{
			std::cout << "truth:  what is your darest secret?\n";
	}
	else if (choice == 0)
	{
			std::cout << "dare: Dance for 1 minute to your favourite song in cluster\n";
	}
	else
		std::cout << ":| Boring. You have just failed\n";

}

void 			ScavTrap::Challenge2()
{
	std::cout << "Directive one: Protect humanity!\nDirective two: Obey Jack at all costs. Directive three: Dance!\n";

}

void 			ScavTrap::Challenge3()
{
	std::cout << "To successfully complete this challenge,\nyou have to eat a tablespoon of cinnamon in a minute or less\nwithout drinking any liquids. Good luc, bastard!" << std::endl;
}

void 			ScavTrap::Challenge4()
{
	std::cout << "Go find the artefact under the table of the person you are evaluating now\nSeriously, check what's under the working desk\n";
}

void 			ScavTrap::Challenge5()
{
	std::cout << "Ask the person on your left or right or whatever to give you a piece of paper.\nNow drwa their portrait. I said now!!!!\n";

}

void 			ScavTrap::Challenge6()
{
	std::cout << "Go to Silpo and buy whatever you want to.\nHowever make sure the final amount paid is a whole number integer not going over 50 hryvnia.\nBring the receipt. Goodluck!\n";
}

void 			ScavTrap::Challenge7()
{
	std::cout << "This one will be easy cause I'm out of imagination.\nSay something nice to aalokhin.\nNow say something that can make her cry. Dare it\n";
}



void				ScavTrap::challengeNewcomer()
{
	void 		(ScavTrap::*functptr[])() =
	{
		&ScavTrap::Challenge1,
		&ScavTrap::Challenge2,
		&ScavTrap::Challenge3,
		&ScavTrap::Challenge4,
		&ScavTrap::Challenge5,
		&ScavTrap::Challenge6,
		&ScavTrap::Challenge7
	};

	if (this->energy_points >= 25)
	{
		
	system("echo \"\033[1;36m\"");
		(this->*functptr[get_Rand_Int(7)])();
		this->energy_points -= 25;

		
		std::cout << this->Name << " has " << this->energy_points << " energy points left\n";

	}
	else
	{
		std::cout << "Hey, dummy, ypu are out of energy points!" << std::endl;

	}

	system("echo \"\033[0m\"");

}


/********************************* Virtual ***************************************/
void			ScavTrap::rangedAttack(std::string const & target)
{
	this->hit_points = hit_points - range_damage;
	std::cout << "SC4V-TP " <<  this->Name << " attacks " << target << " at range, causing " << range_damage + armor_dam_red << " points of damage!" << std::endl;
		
	if (hit_points < 0)
	{
		this->hit_points = 0;
		LevelUp();
	}
	else if (hit_points > max_hit_points)
	{
		this->hit_points = max_hit_points;
	}

	
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	
	this->hit_points = hit_points - melee_damage;

	std::cout << "SC4V-TP " << this->Name << " attacks " << target << " at range, causing "
	<< melee_damage << " points of damage!" << std::endl;

	if (hit_points < 0)
	{
		this->hit_points = 0;
		LevelUp();
	}
	else if (hit_points > max_hit_points)
	{
		this->hit_points = max_hit_points;
	}
}











