#include <iostream>
#include "FragTrap.hpp"


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

void			FragTrap::rangedAttack(std::string const & target)
{
	this->hit_points = hit_points - range_damage;
	std::cout << "FR4G-TP " <<  this->Name << " attacks " << target << " at range, causing " << range_damage + armor_dam_red << " points of damage!" << std::endl;	
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

void			FragTrap::meleeAttack(std::string const & target)
{
	this->hit_points = hit_points - melee_damage;

	std::cout << "FR4G-TP " << this->Name << " attacks " << target << " at range, causing "
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

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	void 		(FragTrap::*functptr[])(std::string const &) =
	{
		&FragTrap::LaserShow,
		&FragTrap::TorgueFiesta,
		&FragTrap::MeatUnicycle,
		&FragTrap::RubberDucky,
		&FragTrap::GunWizard,
		&FragTrap::Mechromagician,
		&FragTrap::SenselessSacrifice
	};
	system("echo \"\033[1;92m\"");
	if (this->energy_points >= 25)
	{	
		(this->*functptr[get_Rand_Int(7)])(target);
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


void			FragTrap::takeDamage(unsigned int amount)
{
	system("echo \"\033[1;92m\"");
	int damage =  (int)amount - armor_dam_red;
	if (damage <= 0)
	{
		
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

	
void		FragTrap::beRepaired(unsigned int amount)
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





FragTrap::FragTrap() : hit_points(100), max_hit_points(100), energy_points(100),
max_energy_points(100), melee_damage(30), range_damage(20), armor_dam_red(5), level(1), dead(false)
{

  std::cout << "Default constructor called: FragTrap -- start bootup sequence." << std::endl;
}

FragTrap::FragTrap(std::string name) : hit_points(100), max_hit_points(100), energy_points(100),
max_energy_points(100), melee_damage(30), range_damage(20), armor_dam_red(5), level(1), dead(false)
{
	Name = name;
	std::cout << "Name constructor: Claptrap -- you couldn't have asked for anything lamer than this." << std::endl;
}


FragTrap::FragTrap(FragTrap const & copy)
{
	std::cout << "Commencing directive three! Uhntssuhntssuhntss--" << std::endl;
	*this = copy;

}

FragTrap & FragTrap::operator=(FragTrap const & over)
{
	this->hit_points = over.get_hit_points();
	this->max_hit_points = over.get_max_hit_points();
	this->energy_points = over.get_energy_points();
	this->max_energy_points = over.get_max_energy_points();
	this->melee_damage = over.get_melee_damage();
	this->range_damage = over.get_range_damage();
	this->armor_dam_red = over.get_armor_dam_red();
	this->Name = over.get_Name();
	return (*this);
}


int			 	FragTrap::get_hit_points() const {return (this->hit_points);} 
int			 	FragTrap::get_max_hit_points() const {return (this->max_hit_points);} 
int			 	FragTrap::get_energy_points() const {return (this->energy_points);} 
int			 	FragTrap::get_max_energy_points() const {return (this->max_energy_points);} 
int			 	FragTrap::get_melee_damage() const {return (this->melee_damage);} 
int			 	FragTrap::get_range_damage() const {return (this->range_damage);} 
int			 	FragTrap::get_armor_dam_red()const {return (this->armor_dam_red);} 
std::string		FragTrap::get_Name() const {return (this->Name);} 

void FragTrap::LevelUp()
{
	system ("echo \"\033[0;105m\" Congrats! Your level went up! \"\033[0m\"");
	
	level++;
	beRepaired(100);
}

FragTrap::~FragTrap()
{
	std::cout << "Default destructor: I created you and I will be the one who murders you to deathhhhhhhhh!" << std::endl;
	return ;
}

void	FragTrap::LaserShow(std::string const & target)
{
	std::cout << "FR4G-TP " <<  Name << " burns to death " << target <<" with Laser and contemplates  " << target << "'s guts turn into BarBeque.\n";

}

void	FragTrap::TorgueFiesta(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " makes  " << target << " walk the plank:\n\"Tortuga means turtle, and that's me. I take my time but I always win.\"" << std::endl;
}

void	FragTrap::MeatUnicycle(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " chops " << target << ".\nThen strips the flesh and salts the wound!\n";

}

void	FragTrap::RubberDucky(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " violently pecks " << target << " to death\n \"I am rubber, and you are so dead!\"\n";

}

void	FragTrap::GunWizard(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " avadakedavaras " << target << ": You can call me fucking Gundalf!\n";
	LevelUp();
}

void	FragTrap::Mechromagician(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " punches in the face this lil bastard " << target << "\nAnarchy and mini-trap and awesomeness, oh my...\n";

}

void	FragTrap::SenselessSacrifice(std::string const & target)
{
	std::cout << "FR4G-TP " <<  this->Name << " sacrifices " << target << "'s life for nothing.\nThe robot is dead, long live the robot!\n";
}


int					FragTrap::get_Rand_Int(unsigned int from)
{

	int	i = (rand() % from);

	return ((i >= 0) ? i : 0);
}


