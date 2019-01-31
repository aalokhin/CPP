#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & copy);
	~ClapTrap();
	ClapTrap & operator=(ClapTrap const & obj);

	int 			level;
	bool 			dead;

	virtual void			rangedAttack(std::string const & target);
	virtual void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			LevelUp();
	void			beRepaired(unsigned int amount);
	int 			get_hit_points() const;
	int 			get_max_hit_points() const;
	int 			get_energy_points() const;
	int 			get_max_energy_points() const;
	int 			get_melee_damage() const;
	int 			get_range_damage() const;
	int 			get_armor_dam_red() const;
	std::string		get_Name() const;

  protected:
	int				hit_points, max_hit_points, energy_points, max_energy_points;
	std::string		Name;
	int				melee_damage, range_damage, armor_dam_red;
	
	int				get_Rand_Int(unsigned int from);

};

#endif
