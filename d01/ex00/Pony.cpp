#include "Pony.hpp"

Pony::Pony(std::string breed, std::string name, bool can_fly)
{

	this->name = name;
	this->breed = breed;
	this->can_fly = can_fly;
	system("echo \"\033[1;36m\"");
	std::cout << "A beautiful "  << this->breed <<  " Pony " << this->name << " was born and ";
	if (this->can_fly)
		std::cout << "it can fly." << std::endl;
	else
		std::cout << "it's  worthless and cannot fly. Better kill it." << std::endl;

}

Pony::~Pony()
{

	system("echo \"\033[1;35m\"");
	std::cout << this->name << " Pony wurde gerade umgebracht!" << std::endl;

	system("echo \"\033[0m\"");
}




