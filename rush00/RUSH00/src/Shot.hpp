#ifndef SHOT_CLASS_H
# define SHOT_CLASS_H

# include "IEntity.hpp"
# include <string>

class Shot : public IEntity
{
public:
	Shot(int y, int x);
	Shot(Shot const & obj);
	~Shot(void);

	Shot& operator=(Shot const &);

	void	update(void);
	void	render(void);
	bool	collide(IEntity &entity);
private:
};

#endif 
