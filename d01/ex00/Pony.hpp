

#ifndef PONY_HPP
#define PONY_HPP


#include <iostream>
#include <cstdlib>

class Pony
{
  public:
  	Pony(std::string breed, std::string name, bool can_fly);
  	~Pony();
  	std::string breed; //Shetland Garrano Galiceno
  	std::string name;
  	bool can_fly;

};

#endif
