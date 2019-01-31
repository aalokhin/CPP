#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap() : ClapTrap()
{
		this->level = 1;
		this->dead = false;

		this->hit_points = 60;
		this->max_hit_points = 60;
		this->energy_points = 120;
		this->max_energy_points = 120;
		this->melee_damage = 60;
		this->range_damage = 5;
		this->armor_dam_red = 0;
		std::cout << "NinjaTrap Default constructor." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap()
{
		this->Name = name;
		this->level = 1;
		this->dead = false;

		this->hit_points = 60;
		this->max_hit_points = 60;
		this->energy_points = 120;
		this->max_energy_points = 120;
		this->melee_damage = 60;
		this->range_damage = 5;
		this->armor_dam_red = 0;
		std::cout << "NinjaTrap Name constructor" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & copy) : ClapTrap()
{
  std::cout << "NinjaTrap Copy constructor." << std::endl;
  *this = copy;
}

NinjaTrap::~NinjaTrap()
{
  std::cout << "NinjaTrap Destructor" << std::endl;
  return ;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & obj)
{
	 std::cout << "NinjaTrap Assignment operator" << std::endl;
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



/******************************* NinJa ************************************/


void			NinjaTrap::ninjaShoebox(  ClapTrap &enemy )
{
	if ( this->energy_points >= 25 )
	{
		this->energy_points -= 25;
		std::cout << "Ninja ninja-sassinates "  << enemy.get_Name() << " with unseen cruelty and skill... " << std::endl;
		enemy.takeDamage(90);
	}
	else
	{
		std::cout << "Oh maaaan.... I am  out of energy points and cannot hit " << enemy.get_Name() << "!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox(  FragTrap &enemy )
{
	if ( this->energy_points >= 25 )
	{
		this->energy_points -= 25;
		std::cout << "Ninja ninja-sassinates "  << enemy.get_Name() << " with unseen cruelty and skill... " << std::endl;
		enemy.takeDamage(90);
	}
	else
	{
		std::cout << "Oh maaaan.... I am  out of energy points and cannot hit " << enemy.get_Name() << "!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox(  ScavTrap &enemy )
{
	if ( this->energy_points >= 25 )
	{
		this->energy_points -= 25;
		std::cout << "Ninja ninja-sassinates "  << enemy.get_Name() << " with unseen cruelty and skill... " << std::endl;
		enemy.takeDamage(90);
	}
	else
	{
		std::cout << "Oh maaaan.... I am  out of energy points and cannot hit " << enemy.get_Name() << "!" << std::endl;
	}
}

void			NinjaTrap::ninjaShoebox(  NinjaTrap &enemy )
{
	if ( this->energy_points >= 25 )
	{
		this->energy_points -= 25;
		std::cout << "Ninja ninja-sassinates "  << enemy.get_Name() << " with unseen cruelty and skill... " << std::endl;
		enemy.takeDamage(90);
	}
	else
	{
		std::cout << "Oh maaaan.... I am  out of energy points and cannot hit " << enemy.get_Name() << "!" << std::endl;
	}
}



/********************************* Virtual ***************************************/
void			NinjaTrap::rangedAttack(std::string const & target)
{
	this->hit_points = hit_points - range_damage;
	std::cout << "Ninja " <<  this->Name << " attacks " << target << " at range, causing " << range_damage + armor_dam_red << " points of damage!" << std::endl;
		
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

void			NinjaTrap::meleeAttack(std::string const & target)
{
	
	this->hit_points = hit_points - melee_damage;

	std::cout << "Ninja " << this->Name << " attacks " << target << " at range, causing "
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












