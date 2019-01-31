#ifndef RADSCORPION_hpp
#define RADSCORPION_hpp

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
	RadScorpion( void );
	RadScorpion( const RadScorpion & );
	~RadScorpion( void );
	RadScorpion			&operator=( const RadScorpion & );
	


};

#endif