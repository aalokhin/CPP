
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
class ScavTrap
{
  private:
  	int 			hit_points, max_hit_points, energy_points, max_energy_points;
  	std::string 	Name;
  	int				melee_damage, range_damage, armor_dam_red;
  	int				get_Rand_Int(unsigned int from);

 public:
 	ScavTrap();
 	ScavTrap(std::string name);
 	ScavTrap(ScavTrap const & copy);
 	ScavTrap & operator=(ScavTrap const & obj);
 	~ScavTrap();

 	int 			level;
 	bool 			dead;
 	void			challengeNewcomer();

 	void			rangedAttack(std::string const & target);
 	void			meleeAttack(std::string const & target);
 	void			takeDamage(unsigned int amount);
 	void			beRepaired(unsigned int amount);
	void			LevelUp();

	void 			Challenge1();
	void 			Challenge2();
	void 			Challenge3();
	void 			Challenge4();
	void 			Challenge5();
	void 			Challenge6();
	void 			Challenge7();

	int get_hit_points() const;
	int get_max_hit_points() const;
	int get_energy_points() const;
	int get_max_energy_points() const;
	int get_melee_damage() const;
	int get_range_damage() const;
	int get_armor_dam_red() const;
	std::string get_Name() const;
};

#endif




