
#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Rebel.hpp"
#include "Mighty.hpp"


int main()
{
  	Sorcerer		robert("Robert", "the Magnificent");
   	Victim			jim("Jimmy");
   	Peon			joe("Joe");
   	Rebel 			Anastasiia("Anastasiia");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(Anastasiia);

	system("echo \"\033[0;32m\"");


	Mighty migty("Champ", "Allmighty");

	migty.polymorph(joe);
	migty.polymorph(Anastasiia);
	migty.get_back_to_life(Anastasiia);
	system("echo \"\033[0m\"");


	return 0;
}
