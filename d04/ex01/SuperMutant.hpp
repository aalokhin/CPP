#ifndef SUPERMUTANT_hpp
#define SUPERMUTANT_hpp

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
	SuperMutant( void );
	SuperMutant( const SuperMutant & );
	~SuperMutant( void );
	SuperMutant	&operator=( const SuperMutant & );
	virtual void takeDamage( int );

};

#endif