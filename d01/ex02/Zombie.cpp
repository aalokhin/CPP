#include "Zombie.hpp"
Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
	system("echo \" \033[1;94m\"");


	std::cout  << "Zombie " << this->name << " has been born!" << std::endl;

	system("echo \"\033[0m\"");

}

Zombie::~Zombie()
{
	std::cout << "Zombie has been destroyed!" << std::endl;

}

void	Zombie::announce( void )
{
	system("echo \"\033[1;33m\"");

	std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
	system("echo \"\033[0m\"");

}