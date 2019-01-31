#include <cstdlib>
#include <typeinfo>
#include <ncurses.h>
#include "Shot.hpp"
#include "Creep.hpp"
#include "IEntity.hpp"

Shot::Shot(int y, int x)
{
	this->_x = x;
	this->_y = y - 1;
}
Shot::Shot(Shot const & obj) : IEntity(obj)
{
	*this = obj;
}
Shot::~Shot(void) {}

Shot& Shot::operator=(Shot const &)
{
	return *this;
}

void Shot::update(void)
{
	this->_counter++;

	if (this->_counter >= 5)
	{
		this->_y = this->_y - 1;
		this->_counter = 0;

		if (this->_y < 0)
			this->_remove = true;
	}
}

bool Shot::collide(IEntity &entity)
{
	return typeid(entity) == typeid(Creep) && checkCollide(entity);
}

void Shot::render(void)
{
	if (this->_y < 0)
		return;

	move(this->_y, this->_x);
	addch('o');
}
