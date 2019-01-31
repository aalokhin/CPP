#include <ncurses.h>
#include <string>
#include <typeinfo>
#include "Player.hpp"
#include "IEntity.hpp"

const int Player::_xSize = 3;
const std::string Player::_model = "8";

Player::Player(void) {}
Player::Player(Player const & obj) : IEntity(obj)		
{
	*this = obj;
}
Player::~Player(void) {}

Player& Player::operator=(Player const &)
{
	return *this;
}

std::string Player::getModel(void)
{
	return this->_model;
}

void Player::update(void)
{

}

void Player::render(void)
{
	move(this->_y, this->_x);
	addstr(this->getModel().c_str());
}

bool Player::collide(IEntity &)
{
	return false;
}
