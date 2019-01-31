#ifndef NALIST_CLASS_H
# define NALIST_CLASS_H

# include "IEntity.hpp"

class NAList
{
public:
	NAList(void);
	NAList(NAList const &);
	~NAList(void);

	NAList& operator=(NAList const &);

	IEntity **getArray(void) const;
	size_t getSize(void) const;
	size_t getHigh(void) const;
	size_t getCount(void) const;
	void add(IEntity *entity);
	void remove(size_t i, bool del = true);
private:
	IEntity	**_lst;
	size_t	_size;
	size_t	_count;
	size_t	_high;
};

#endif
