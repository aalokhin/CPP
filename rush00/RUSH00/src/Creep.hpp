#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H

# include "IEntity.hpp"

class Creep : public IEntity
{
public:
	Creep();
	Creep(Creep const & obj);
	~Creep(void);

	Creep& operator=(Creep const &);

	char	getType(void);
	void	update(void);
	void	render(void);
	bool	collide(IEntity &entity);

private:
	char	_type;
	int		_speed;
	static char _types[6];
};

#endif 

