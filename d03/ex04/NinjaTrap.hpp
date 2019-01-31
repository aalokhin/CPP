#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

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
};

#endif


