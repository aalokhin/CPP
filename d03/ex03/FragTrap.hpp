#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string usname);
    FragTrap(FragTrap const & copy);
    ~FragTrap();
    FragTrap & operator=(FragTrap const & over);
    
    void 	vaulthunter_dot_exe(std::string const & target);
    
    void	LaserShow(std::string const & target);
    void	TorgueFiesta(std::string const & target);
    void	MeatUnicycle(std::string const & target);
    void	RubberDucky(std::string const & target);
    void	GunWizard(std::string const & target);
    void	Mechromagician(std::string const & target);
    void	SenselessSacrifice(std::string const & target);
    void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
};

#endif
