#include <cstdlib>
#include <ncurses.h>
#include <typeinfo>
#include "Creep.hpp"
#include "Shot.hpp"
#include "IEntity.hpp"

char Creep::_types[6] = {
	'W' , 'w' , 'W', 'w', 'W', 'w'
};

Creep::Creep()
{
	this->_speed = std::rand() % 20 + 40;
	this->_type = Creep::_types[std::rand() % 6];
	this->_x = std::rand() % COLS;
	this->_y = 0;
}
Creep::Creep(Creep const & obj) : IEntity(obj)
{
	*this = obj;
}
Creep::~Creep(void) {}

Creep& Creep::operator=(Creep const &)
{
	return *this;
}

char Creep::getType(void)
{
	return this->_type;
}

void Creep::update(void)
{
	this->_counter++;

	if (this->_counter >= _speed)
	{
		this->_y = this->_y + 1;
		this->_counter = 0;

		if (this->_y >= LINES)
			this->_remove = true;
	}
}

void Creep::render(void)
{
	if (this->_y >= LINES)
		return;
	move(this->_y, this->_x);
	addch(this->getType());
}

bool Creep::collide(IEntity &entity)
{
	return typeid(entity) == typeid(Shot) && checkCollide(entity);
}
