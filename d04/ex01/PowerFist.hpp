#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:
	PowerFist( void );
	PowerFist( const PowerFist & );
	~PowerFist( void );

	PowerFist			&operator=( const PowerFist & );

	virtual void		attack( void ) const;

};

#endif		