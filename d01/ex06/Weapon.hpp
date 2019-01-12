#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>


class Weapon
{
  public:
  	Weapon(std::string weapon_type);
    ~Weapon();

    
    const std::string	&getType(void) const;
    void 				setType(std::string weapon_type);

    std::string _type;
};

#endif
