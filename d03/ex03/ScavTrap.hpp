#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & copy);
    ~ScavTrap();

    ScavTrap & operator=(ScavTrap const & obj);
    void            rangedAttack(std::string const & target);
    void            meleeAttack(std::string const & target);
    void 			challengeNewcomer();
    void 			Challenge1();
    void 			Challenge2();
    void 			Challenge3();
    void 			Challenge4();
    void 			Challenge5();
    void 			Challenge6();
    void 			Challenge7();
};

#endif
