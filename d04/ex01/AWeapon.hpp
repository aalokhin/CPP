#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <string>
#include <iostream>


class AWeapon {

public:
	AWeapon( void );
	AWeapon( const std::string &name, int apcost, int damage );
	AWeapon( const AWeapon & );
	virtual ~AWeapon( void );
	AWeapon			&operator=( const AWeapon & );

	std::string		getName( void ) const;
	int				getAPCost( void ) const;
	int				getDamage( void ) const;


	virtual void	attack( void ) const = 0;

private:
	std::string		_name;
	int				_apcost;
	int				_damage;

};

#endif		