#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void): FragTrap(), NinjaTrap() {

	level = 1;
	dead = false;

	hit_points = 100;
	max_hit_points = 100;
	energy_points = 120;
	max_energy_points = 120;

	melee_damage = 60;
	range_damage = 20;
	armor_dam_red = 5;
	std::cout << "new supertrap is being born" << std::endl;


	return;
}

SuperTrap::SuperTrap(std::string const name): FragTrap(name), NinjaTrap(name) {

	hit_points = 100;
	max_hit_points = 100;
	energy_points = 120;
	max_energy_points = 120;
	level = 1;
	dead = false;
	melee_damage = 60;
	range_damage = 20;
	armor_dam_red = 5;

	
	Name = name;
	std::cout << "new supertrap is being born with name " << Name << std::endl;

	return;
}

SuperTrap::SuperTrap(SuperTrap const & obj): FragTrap(obj), NinjaTrap(obj) {

	std::cout << "They are making a lame copy of supertrap" << std::endl;
	*this = obj;
	return;
}

SuperTrap::~SuperTrap() {

	std::cout << "Don't murder me please don't I suuuuuper traaap...." << std::endl;
	return;
}

SuperTrap &  SuperTrap::operator=(SuperTrap const & obj) {

	this->Name = obj.get_Name();
	this->hit_points = obj.hit_points;
	this->max_hit_points = obj.max_hit_points;
	this->energy_points = obj.energy_points;
	this->max_energy_points = obj.max_energy_points;
	this->level = obj.level;
	this->dead = obj.dead;
	this->melee_damage = obj.melee_damage;
	this->range_damage = obj.range_damage;
	this->armor_dam_red = obj.armor_dam_red;
	return *this;
}

void	SuperTrap::rangedAttack(std::string const & target) {

	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target) {

	NinjaTrap::rangedAttack(target);
}