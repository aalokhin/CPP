#include <iostream>
#include "ScavTrap.hpp"

static const std::string funny_quotes[16] = {
"Once I march up to Helios with a bad-ass army of robots, I'll be un-fired so quickly,\n it'll make Tassiter's pedo-mustache spin off his big gross ugly face!",
"These dick bags are just nuts. Get it dick bags, nuts?",
"I WANT YOU TO BLOW UP ... THE OCEAN!", 
"BRING ME A BUCKET AND I'LL SHOW YOU A BUCKET",
"BLAKE, WHERE'S A BLOODY VIOLIN?!",
"This planet smells like hemmorroids wrapped in bacon",
"I LIKE MY ENEMIES HOW I LIKE MY COFFEE, IN THE BUTT",
"Anyway the moral is, you're a total bitch",
"Domo arigato suckaass!",
"CATCH-A-RIIIIIIIIIIIIIIDE",
"I HAVE THE SHINIEST MEATBICYCLE",
"I must've been horrifyingly cruel to puppies in a previous life\n to receive this kind of treatment",
"I'm ready, yank me", 
"It's finally over...I see a bright light. It's blinding...\n beautiful...no, wait. That's just the sun. Shit.",
"I HAVE ONE QUESTION FOR YOU. EXPLOSIONS?",
"NOTHING IS MORE BADASS THAN TREATING A WOMAN WITH RESPECT!"
};

void 			ScavTrap::Challenge1()
{
	std::string choice;
	std::cout << "truth or dare?\n";

	std::cin >> choice;
	if (choice == "truth") 
	{
			std::cout << "what is your darest secret?\n";
	}
	else if (choice == "dare")
	{
			std::cout << "Dance for 1 minute to your favourite song in cluster\n";
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
	std::cout << funny_quotes[get_Rand_Int(16)] << std::endl;

	system("echo \"\033[0m\"");

}


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

	std::cout << funny_quotes[get_Rand_Int(16)] << std::endl;
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

	std::cout << funny_quotes[get_Rand_Int(16)] << std::endl;

}



void			ScavTrap::takeDamage(unsigned int amount)
{
	int damage =  (int)amount - armor_dam_red;
	if (damage <= 0)
	{
		system("echo \"\033[1;92m\"");
		std::cout << Name << " lucky bastard!\nThe damage was insignificant, you didn't get even a scratch...\n";
		return ;
	}
	system("echo \"\033[1;91m\"");

	energy_points -= damage;
	if (energy_points < 0)
	{
		energy_points = 0;
		std::cout << "Your game is over " << Name << "!\nYou've been brave but that wasn't enough...\n";
		dead = true;
	}
	else
	{
		system("echo \"\033[1;91m\"");
		std::cout << "Energy loss is " << damage << "!" << std::endl;
		std::cout << Name << " has " << energy_points << " energy points left!" << std::endl;
	}
	system("echo \"\033[0m\"");
}

	
void		ScavTrap::beRepaired(unsigned int amount)
{
	system("echo \"\033[0;94m\" ");
	if (energy_points + (int)amount >= max_energy_points)
	{
		energy_points = max_energy_points;
		hit_points = max_hit_points;
		std::cout << Name << "! You are now as sound as a bell!\nWhat do you need more energy for?\n";
	}
	else
	{
		hit_points = max_hit_points;
		energy_points += int(amount);
		std::cout << Name << ", congrats! Here is your bit of health repair\n";


	}
	system("echo \"\033[0m\"");

}





ScavTrap::ScavTrap()
{
	this->level = 1;
	this->dead = false;
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_damage = 20;
	this->range_damage = 15;
	this->armor_dam_red = 3;

	std::cout << "Default daughter constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	Name = name;

	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->melee_damage = 20;
	this->range_damage = 15;
	this->armor_dam_red = 3;
	this->level = 1;
	this->dead = false;

	std::cout << "Name daughter constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy)
{
	std::cout << "Copy daughter constructor." << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Daughter Destructor" << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & obj)
{
	this->hit_points = obj.get_hit_points();
	this->max_hit_points = obj.get_max_hit_points();
	this->energy_points = obj.get_energy_points();
	this->max_energy_points = obj.get_max_energy_points();
	this->melee_damage = obj.get_melee_damage();
	this->range_damage = obj.get_range_damage();
	this->armor_dam_red = obj.get_armor_dam_red();
	this->Name = obj.get_Name();
	this->level = obj.level;
	this->dead = obj.dead;
	return (*this);
}

int					ScavTrap::get_Rand_Int(unsigned int from)
{
	int	i = (rand() % from);
	return ((i >= 0) ? i : 0);
}

void ScavTrap::LevelUp()
{
	system ("echo \"\033[0;105m\" Congrats! Your level went up! \"\033[0m\"");
	level++;
	beRepaired(100);
}



int			 			ScavTrap::get_hit_points() const {return (this->hit_points);} 
int			 			ScavTrap::get_max_hit_points() const {return (this->max_hit_points);} 
int			 			ScavTrap::get_energy_points() const {return (this->energy_points);} 
int			 			ScavTrap::get_max_energy_points() const {return (this->max_energy_points);} 
int			 			ScavTrap::get_melee_damage() const {return (this->melee_damage);} 
int			 			ScavTrap::get_range_damage() const {return (this->range_damage);} 
int			 			ScavTrap::get_armor_dam_red()const {return (this->armor_dam_red);} 
std::string		ScavTrap::get_Name() const {return (this->Name);} 