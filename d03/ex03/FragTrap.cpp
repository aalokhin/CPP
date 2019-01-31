#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
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
		std::cout << "FragTrap Default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
		this->Name = name;
		this->level = 1;
		this->dead = false;

		this->hit_points = 100;
		this->max_hit_points = 100;
		this->energy_points = 100;
		this->max_energy_points = 100;
		this->melee_damage = 30;
		this->range_damage = 20;
		this->armor_dam_red = 5;
		std::cout << "FragTrap Name constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap()
{
  std::cout << "FragTrap Copy constructor." << std::endl;
  *this = copy;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap Destructor" << std::endl;
  return ;
}

FragTrap & FragTrap::operator=(FragTrap const & obj)
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

/************************************************* FRAG TRAP FUNCS *************************************************/


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

	if (this->energy_points >= 25)
	{
		
		system("echo \"\033[1;92m\"");

		(this->*functptr[get_Rand_Int(7)])(target);
		this->energy_points -= 25;

		system("echo \"\033[0m\"");
		std::cout << this->Name << " has " << this->energy_points << " energy points left\n";

	}
	else
	{
		std::cout << "Hey, dummy, ypu are out of energy points!" << std::endl;

	}
	system("echo \"\033[0m\"");


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


/************************Virtual*********************************/


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

	


}







