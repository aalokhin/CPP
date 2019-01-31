#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &);
	~NinjaTrap( void );
	NinjaTrap &operator=( const NinjaTrap & );

	void	ninjaShoebox(  ClapTrap & enemy);
	void	ninjaShoebox(  FragTrap & enemy);
	void	ninjaShoebox(  ScavTrap & enemy);
	void	ninjaShoebox(  NinjaTrap & enemy);
	void    rangedAttack(std::string const & target);
    void    meleeAttack(std::string const & target);
};

#endif


