#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main(void)
{
	std::srand(time(NULL));

	ClapTrap Clap_1("PraRobot");
	
	while (Clap_1.level < 2 && Clap_1.dead != true)
	{
	  Clap_1.rangedAttack("zombie");
	  Clap_1.meleeAttack("enemy");
	  Clap_1.takeDamage(20);
	  Clap_1.beRepaired(5);

	}
	
	FragTrap FRG("Anastasiia");
	
	while (FRG.level < 3 && FRG.dead != true)
	{

		FRG.rangedAttack("Scary lady");
		FRG.meleeAttack("Enemy");
		FRG.vaulthunter_dot_exe("Mingaszudtinov");
		FRG.takeDamage(20);
		FRG.beRepaired(5);

	}

	ScavTrap Scav_the_1st("SomeScav");
	
	while (Scav_the_1st.level < 3 && Scav_the_1st.dead != true)
	{
		Scav_the_1st.rangedAttack("IRON door");
		Scav_the_1st.meleeAttack("WOOD door");
		Scav_the_1st.challengeNewcomer();
	}
	
	NinjaTrap NJT("Ninjaaaaa");
	ScavTrap enemy1("Enemy1");
	ClapTrap enemy2("Enemy2");
	FragTrap enemy3("Enemy3");

	while(enemy1.dead != true)
	{
		NJT.ninjaShoebox(enemy1);
	}
	while(enemy1.dead != true)
	{
		NJT.ninjaShoebox(enemy2);
	}
	while(enemy1.dead != true)
	{
		NJT.ninjaShoebox(enemy3);
	}

	NinjaTrap NJT1("HeyNinja");

	while (NJT1.level < 3 && NJT1.dead != true)
	{
		NJT1.rangedAttack("IRON door");
		NJT1.meleeAttack("WOOD door");
		FRG.takeDamage(20);
		FRG.beRepaired(5);
	}


	return 0;
}

