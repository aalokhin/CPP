#include "ClapTrap.hpp"

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

void			ClapTrap::rangedAttack(std::string const & target)
{
	this->hit_points = hit_points - range_damage;
	std::cout  << "CL4P" <<   this->Name << " attacks " << target << " at range, causing " << range_damage + armor_dam_red << " points of damage!" << std::endl;
		
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

void			ClapTrap::meleeAttack(std::string const & target)
{
	this->hit_points = hit_points - melee_damage;

	std::cout << "CL4P" << this->Name << " attacks " << target << " at range, causing "
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


void			ClapTrap::takeDamage(unsigned int amount)
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

	
void		ClapTrap::beRepaired(unsigned int amount)
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


ClapTrap::ClapTrap() : hit_points(100), max_hit_points(100), energy_points(100),
max_energy_points(100), melee_damage(30), range_damage(20), armor_dam_red(5)
{
	this->level = 1;
	this->dead = false;
  std::cout << "Default constructor called: ClapTrap -- start bootup sequence." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hit_points(100), max_hit_points(100), energy_points(100),
max_energy_points(100), melee_damage(30), range_damage(20), armor_dam_red(5)
{
	this->Name = name;
	this->level = 1;
	this->dead = false;
	std::cout << "Name constructor: Claptrap -- you couldn't have asked for anything lamer than this." << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const & copy)
{
	std::cout << "Commencing directive three! Uhntssuhntssuhntss--" << std::endl;
	*this = copy;

}

ClapTrap & ClapTrap::operator=(ClapTrap const & obj)
{
	this->hit_points = obj.get_hit_points();
	this->max_hit_points = obj.get_max_hit_points();
	this->energy_points = obj.get_energy_points();
	this->max_energy_points = obj.get_max_energy_points();
	this->melee_damage = obj.get_melee_damage();
	this->range_damage = obj.get_range_damage();
	this->armor_dam_red = obj.get_armor_dam_red();
	this->Name = obj.get_Name();
	return (*this);
}


int			 	ClapTrap::get_hit_points() const {return (this->hit_points);} 
int			 	ClapTrap::get_max_hit_points() const {return (this->max_hit_points);} 
int			 	ClapTrap::get_energy_points() const {return (this->energy_points);} 
int			 	ClapTrap::get_max_energy_points() const {return (this->max_energy_points);} 
int			 	ClapTrap::get_melee_damage() const {return (this->melee_damage);} 
int			 	ClapTrap::get_range_damage() const {return (this->range_damage);} 
int			 	ClapTrap::get_armor_dam_red()const {return (this->armor_dam_red);} 
std::string		ClapTrap::get_Name() const {return (this->Name);} 

void ClapTrap::LevelUp()
{
	system ("echo \"\033[0;105m\" Congrats! Your level went up! \"\033[0m\"");
	level++;
	beRepaired(100);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor: I created you and I will be the one who is murdering you!" << std::endl;
	return ;
}

int					ClapTrap::get_Rand_Int(unsigned int from)
{

	int	i = (rand() % from);

	return ((i >= 0) ? i : 0);
}


