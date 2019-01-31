#include <iostream>
#include "FragTrap.hpp"


int main(void)
{
  std::srand(time(NULL));

  FragTrap FRG("Anastasiia");

  FragTrap Alice("Alice");
  FragTrap FRG2(Alice);
  FragTrap FRG3;
  FRG3 = FRG2;

  while (FRG.level <= 3 && FRG.dead != true)
  {

    FRG.rangedAttack("Scary lady");
    FRG.meleeAttack("Enemy");
    FRG.vaulthunter_dot_exe("Mingaszudtinov");
    FRG.takeDamage(20);
    FRG.beRepaired(5);

  }

  while (FRG2.level <= 3 && FRG2.dead != true)
  {

    FRG2.rangedAttack("stalker");
    FRG2.meleeAttack("Shitty champ");
    FRG2.vaulthunter_dot_exe("sekretarsha Kopeiiki");
    FRG2.takeDamage(20);


  }

  while (Alice.level <= 3 && Alice.dead != true)
  {

    Alice.rangedAttack("growler");
    Alice.meleeAttack("enemy");
    Alice.vaulthunter_dot_exe("Bloody Merry");
    Alice.takeDamage(20);

  }

  while (FRG3.level <= 3 && FRG3.dead != true)
  {

    FRG3.rangedAttack("Trump");
    FRG3.meleeAttack("ghost");
    FRG3.vaulthunter_dot_exe("Semen Strogov");
    FRG3.takeDamage(20);

  }
  return 0;
}



