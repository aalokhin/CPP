#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
int main(void)
{
	std::srand(time(NULL));
	
	ClapTrap Clap_1("PraRobot");
	ClapTrap Clap_2(Clap_1);
	ClapTrap Clap_3;
	Clap_3 = Clap_2;

	while (Clap_1.level < 2 && Clap_1.dead != true)
	{
	  Clap_1.rangedAttack("zombie");
	  Clap_1.meleeAttack("enemy");
	  Clap_1.takeDamage(20);
	  Clap_1.beRepaired(5);

	}
	while (Clap_2.level < 2 && Clap_2.dead != true)
	{
	 Clap_2.rangedAttack("zombie");
	 Clap_2.meleeAttack("enemy");
	  Clap_2.takeDamage(20);
	  Clap_2.beRepaired(5);
	}
	while (Clap_3.level < 2 && Clap_3.dead != true)
	{
	  Clap_3.rangedAttack("zombie");
	  Clap_3.meleeAttack("enemy");
	  Clap_3.takeDamage(20);
	  Clap_3.beRepaired(5);
	}

std::cout << "******************************************************" << std::endl;

	FragTrap FRG("Anastasiia");
	FragTrap Alice("Alice");
	FragTrap FRG2(Alice);
	FragTrap FRG3;
	FRG3 = FRG2;

	while (FRG.level < 3 && FRG.dead != true)
	{

		FRG.rangedAttack("Scary lady");
		FRG.meleeAttack("Enemy");
		FRG.vaulthunter_dot_exe("Mingaszudtinov");
		FRG.takeDamage(20);
		FRG.beRepaired(5);

	}

	while (FRG2.level < 3 && FRG2.dead != true)
	{

		FRG2.rangedAttack("stalker");
		FRG2.meleeAttack("Shitty champ");
		FRG2.vaulthunter_dot_exe("sekretarsha Kopeiiki");
		FRG2.takeDamage(20);


	}

	while (Alice.level < 3 && Alice.dead != true)
	{

		Alice.rangedAttack("growler");
		Alice.meleeAttack("enemy");
		Alice.vaulthunter_dot_exe("Bloody Merry");
		Alice.takeDamage(20);

	}

	while (FRG3.level < 3 && FRG3.dead != true)
	{

		FRG3.rangedAttack("Trump");
		FRG3.meleeAttack("ghost");
		FRG3.vaulthunter_dot_exe("Semen Strogov");
		FRG3.takeDamage(20);

	}
std::cout << "******************************************************" << std::endl;

	ScavTrap Scav_the_1st("SomeScav");
	ScavTrap Scav_the_2nd(Scav_the_1st);
	ScavTrap Scav_the_3d;
	Scav_the_3d = Scav_the_2nd;

	while (Scav_the_1st.level < 3 && Scav_the_1st.dead != true)
	{
		Scav_the_1st.rangedAttack("IRON door");
		Scav_the_1st.meleeAttack("WOOD door");
		Scav_the_1st.challengeNewcomer();
	}
	while (Scav_the_2nd.level < 3 && Scav_the_1st.dead != true)
	{
		Scav_the_2nd.rangedAttack("IRON door");
		Scav_the_2nd.meleeAttack("WOOD door");
		Scav_the_2nd.challengeNewcomer();
	}
	while (Scav_the_3d.level < 3 && Scav_the_1st.dead != true)
	{
		Scav_the_3d.rangedAttack("IRON door");
		Scav_the_3d.meleeAttack("WOOD door");
		Scav_the_3d.challengeNewcomer();
	}

	
	return 0;
}

