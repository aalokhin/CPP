#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() { 
	std::cout << "ZombieEvent Constructor called" << std::endl;
	return;
}

ZombieEvent::~ZombieEvent() { 
	std::cout << "ZombieEvent Destructor called" << std::endl;
	return;
}

void			ZombieEvent::setZombieType(Zombie* new_zombie)
{

	system("echo \"\033[0m\"");

	std::cout << "What is your Zombie?" << std::endl;
	std::cin >> new_zombie->type;
	if (std::cin.fail())
		exit (0);
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *new_zombie;
	system("echo \" \033[1;94m\"");
	new_zombie = new Zombie(name, "NaN");
	setZombieType(new_zombie);
	system("echo \"\033[0m\"");
	return new_zombie;
}

std::string ZombieEvent::RandomName() //fix the rand non-literal characters
{
	srand(time(0));
	
	int max_len = 9;
	int len = rand() % (max_len - 1);
	int i;
	char r_name[len + 1];
	r_name[len] = '\0';

	
	for(i = 0; i < len; i++)
	{
		r_name[i] =  (char)((rand() % 52) + 65);
	}
	std::string rand_res(r_name);
	return rand_res;
}

std::string ZombieEvent::RandomType()
{
	srand(time(0));
	
	int max_len = 12;
	int len = rand() % (max_len - 1);
	int i;
	char r_name[len + 1];
	r_name[len] = '\0';

	
	for(i = 0; i < len; i++)
	{
		r_name[i] =  (char)((rand() % 52) + 65);
	}
	std::string rand_res(r_name);
	return rand_res;
}

Zombie* ZombieEvent::randomChump()
{
	Zombie *rand_zombie;

	system("echo \"\033[1;32m\"");

	//std::cout << "ZombieEvent Random Creation called" << std::endl;
	std::string name_r(RandomName());
	std::string type_r(RandomType());

	rand_zombie = new Zombie(name_r, type_r);
	//rand_zombie->announce();
	system("echo \"\033[0m\"");
	return rand_zombie;

}

