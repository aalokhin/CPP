#include "Character.hpp"


Character::Character( void ) : _AP(40), _weapon(NULL) {return;}
Character::Character( const std::string &name ):  _name(name), _AP(40), _weapon(NULL){return;}
Character::~Character( void ){return;}

Character::Character( const Character & Copy){*this = Copy;}

Character	&Character::operator=( const Character & Copy)
{
	this->_name = Copy._name;
	this->_AP = Copy._AP;
	this->_weapon = Copy._weapon;
	return *this;
}

std::string				Character::getName( void ) const { return this->_name; }

int						Character::getAP( void ) const { return this->_AP; }

AWeapon					*Character::getWeapon( void ) const { return this->_weapon; }

void					Character::equip( AWeapon *weapon ){ _weapon = weapon; }

void					Character::recoverAP( void )
{
	_AP += 10;
	_AP = (_AP > 40 ) ? 40 : _AP;
}


std::ostream	&operator<<( std::ostream &o, const Character &character )
{
	o << character.getName() << " has " << character.getAP() << " AP and ";

	if ( character.getWeapon() != NULL )
	{
		o << "wields a " << character.getWeapon()->getName() << std::endl;
	}
	else 
	{
		o << "is unarmed" << std::endl;
	}
	return o;
}

void					Character::attack( Enemy *enemy )
{
	if (enemy->getHP() <= 0)
		return ;
	if ( this->_weapon != NULL && _AP >= _weapon->getAPCost() && enemy->getHP() > 0)
	{

		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;

		_AP -= _weapon->getAPCost();
		_weapon->attack();
		int amount = _weapon->getDamage();
		enemy->takeDamage(amount);
	}
	if (enemy->getHP() <= 0)
		delete enemy;
}


