#include "AWeapon.hpp"

AWeapon::AWeapon( void ) {return ;}

AWeapon::AWeapon( const std::string &name, int apcost, int damage ) : 
	_name(name),
	_apcost(apcost),
	_damage(damage)
	
{ 
	return ;
}

AWeapon::AWeapon( const AWeapon &Copy )
{ *this = Copy; }

AWeapon::~AWeapon( void ) { return ; }



AWeapon				&AWeapon::operator=( const AWeapon &Copy )
{
	this->_name = Copy._name;
	this->_apcost = Copy._apcost;
	this->_damage = Copy._damage;
	return *this;
}

std::string		AWeapon::getName( void ) const
{	return this->_name; }

int				AWeapon::getAPCost( void ) const
{	return this->_apcost; }

int				AWeapon::getDamage( void ) const
{ 	return this->_damage; }

