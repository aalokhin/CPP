#ifndef ENEMY_hpp
#define ENEMY_hpp

#include <string>
#include <iostream>

class Enemy {

public:
	Enemy( void );
	Enemy( int HP, const std::string &type );
	Enemy( const Enemy & );
	virtual ~Enemy( void );
	Enemy			&operator=( const Enemy & );
	std::string		getType() const;
	int				getHP() const;
	virtual void	takeDamage( int );
	void			SetHP(int );

private:
	std::string		_type;
	int				_HP;

};

#endif	