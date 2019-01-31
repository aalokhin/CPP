#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap
{
	private:
		int 			hit_points, max_hit_points, energy_points, max_energy_points;
		int 			melee_damage, range_damage, armor_dam_red;
		std::string 	Name;
		int				get_Rand_Int(unsigned int from);
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & copy);
		FragTrap &operator=( const FragTrap & );
		~FragTrap();

		int 	level;
		bool 	dead;
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	LaserShow(std::string const & target);
		void	TorgueFiesta(std::string const & target);
		void	MeatUnicycle(std::string const & target);
		void	RubberDucky(std::string const & target);
		void	GunWizard(std::string const & target);
		void	Mechromagician(std::string const & target);
		void	SenselessSacrifice(std::string const & target);
		void	LevelUp();

		void 			vaulthunter_dot_exe(std::string const & target);


		/* Get initial data*/
		int 			get_hit_points() const;
		int 			get_max_hit_points() const;
		int 			get_energy_points() const;
		int 			get_max_energy_points() const;
		int 			get_melee_damage() const;
		int 			get_range_damage() const;
		int 			get_armor_dam_red() const;
		std::string		get_Name() const;

};

#endif
