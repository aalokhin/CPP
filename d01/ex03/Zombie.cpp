#include "Zombie.hpp"


Zombie::Zombie()
{
	std::cout  << " 🧟‍♀️ ";
}

Zombie::~Zombie()
{
	system("echo \"\033[1;34m\"");
	std::cout << "Zombie has been destroyed!" << std::endl;
	system("echo \"\033[0m\"");

}

void	Zombie::announce( void )
{
	system("echo \"\033[1;33m\"");
	std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
	system("echo \"\033[0m\"");

}