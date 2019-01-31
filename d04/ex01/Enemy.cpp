#include "Enemy.hpp"

Enemy::Enemy( void ) { return ; }

Enemy::Enemy( int HP, const std::string &type ) : _type(type), _HP(HP) { return ; }

Enemy::Enemy( const Enemy &Copy ) { *this = Copy; }

Enemy::~Enemy( void ) { return ; }

Enemy				&Enemy::operator=( const Enemy &Copy )
{
	this->_type = Copy._type;
	this->_HP = Copy._HP;
	return *this;
}

std::string			Enemy::getType() const{ return this->_type; }

int					Enemy::getHP() const { return this->_HP; }

void 				Enemy::SetHP(int amount) { _HP += amount; }


void				Enemy::takeDamage( int amount )
{
	if ( _HP > 0 && amount > 0 )
	{
		_HP -= amount;
	}
	_HP = (_HP < 0) ? 0 : _HP;
}