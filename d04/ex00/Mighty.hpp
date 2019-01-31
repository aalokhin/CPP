#ifndef MIGHTY_HPP
#define MIGHTY_HPP

#include "Sorcerer.hpp"

class Mighty: public Sorcerer {

public:
	Mighty( void );
	Mighty( std::string name, std::string title );
	Mighty( const Mighty &Copy );
	~Mighty( void );
	Mighty &operator=( const Mighty &Copy );

	void get_back_to_life( const Victim & );
	

};


#endif