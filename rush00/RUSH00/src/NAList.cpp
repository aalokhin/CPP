

#include <cstddef>
#include "NAList.hpp"
#include "IEntity.hpp"

NAList::NAList(void) : _size(16 * 1024), _count(0), _high(0)
{
	this->_lst = new IEntity *[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_lst[i] = NULL;
}
NAList::NAList(NAList const &) {}
NAList::~NAList(void)
{
	delete[] this->_lst;
}

NAList& NAList::operator=(NAList const &)
{
	return *this;
}

IEntity **NAList::getArray(void) const
{
	return this->_lst;
}

size_t NAList::getCount(void) const
{
	return this->_count;
}
size_t NAList::getSize(void) const
{
	return this->_size;
}

size_t NAList::getHigh(void) const
{
	return this->_high + 1;
}

void NAList::add(IEntity *entity)
{
	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->_lst[i] == NULL)
		{
			this->_lst[i] = entity;

			this->_count++;

			if (this->_high <= i)
				this->_high = i;

			return;
		}
	}
}

void NAList::remove(size_t i, bool del)
{
	if (this->_lst[i] == NULL)
		return;

	if (del)
		delete this->_lst[i];
	this->_lst[i] = NULL;

	if (this->_high == i)
	{
		for (int i = this->_high; i >= 0; i--)
		{
			if (this->_lst[i] != NULL)
			{
				this->_high = i;
				return;
			}
		}
	}
}
