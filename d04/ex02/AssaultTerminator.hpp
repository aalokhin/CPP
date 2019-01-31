#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>


class AssaultTerminator: public ISpaceMarine
{
	public:
		virtual ~AssaultTerminator( void );
		AssaultTerminator( void );
		AssaultTerminator( AssaultTerminator const & marine );
		AssaultTerminator & operator=( AssaultTerminator const & marine );
		virtual ISpaceMarine *clone( void ) const;
		virtual void battleCry( void ) const;
		virtual void rangedAttack( void ) const;
		virtual void meleeAttack( void ) const;
		int			getHP( void ) const;
	private:
		int			_HP;
};

#endif