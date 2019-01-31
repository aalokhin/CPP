#include "AWeapon.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

int main()
{
	std::cout << std::endl << "*************~~~~~~~~~~BASIC~TESTS~~~~~~~~*************" << std::endl << std::endl;

	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;


	Character *nastia = new Character("aalokhin");
	Enemy *supermutant =	new SuperMutant();
	Enemy *scorpio = new RadScorpion();


	AWeapon *w1 = new PowerFist();
	AWeapon *w2 = new PlasmaRifle();

	nastia->equip(w1);
	std::cout << std::endl << "*************~~~~~~~~~~SUPERMUTANT~TESTS~~~~~~~~*************" << std::endl << std::endl;
	
	while(supermutant->getHP() > 0 && nastia->getAP() > 0)
	{
		nastia->attack(supermutant);
		std::cout << *nastia;
	}

	std::cout << std::endl << "*************~~~~~~~~~~WE~ARE~OUT~OF~AP~TESTS~~~~~~~~*************" << std::endl << std::endl;

	while(scorpio->getHP() > 0 && nastia->getAP() > 0)
	{
		nastia->attack(scorpio);
		std::cout << *nastia;
	}

	nastia->attack(scorpio);
	std::cout << std::endl << "                      Recovery ........                     " << std::endl << std::endl;

	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	std::cout << *nastia;

	nastia->attack(supermutant);
	std::cout << *nastia;

	std::cout << std::endl << "*************~~~~~~~~~~~~~~SCORPIO~TESTS~~~~~~~~~~~~*************" << std::endl << std::endl;


	while(scorpio->getHP() > 0 && nastia->getAP() > 0)
	{
		nastia->attack(scorpio);
		std::cout << *nastia;
	}
	std::cout << std::endl << "                      Recovery ........                     " << std::endl << std::endl;
	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	nastia->recoverAP();
	std::cout << *nastia;

	nastia->equip(NULL);
	std::cout << *nastia;
	nastia->equip(w2);
	std::cout << *nastia;


	std::cout << std::endl << "*************~~~~~~~~~~~~~~THE~END~~~~~~~~~~~~~~*************" << std::endl;
	
	return 0;
}
