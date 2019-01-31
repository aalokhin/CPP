#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include <iostream>

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:

	SuperTrap(void);
    SuperTrap(std::string const name);
	SuperTrap(SuperTrap const & copy);
    ~SuperTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	SuperTrap &	operator=(SuperTrap const &obj);
};

#endif