#ifndef ENTITY_INTERFACE_H
# define ENTITY_INTERFACE_H

class IEntity
{
public:
	IEntity(void);
	IEntity(IEntity const & obj);
	virtual ~IEntity(void);

	IEntity& operator=(IEntity const &rhs);

	virtual void update(void) = 0;
	virtual void render(void) = 0;
	virtual bool collide(IEntity &entity) = 0;

	void setPosition(int y, int x);

	bool shouldRemove(void);

	int getY(void);
	void setY(int y);

	int getX(void);
	void setX(int x);

	bool checkCollide(IEntity &entity);
protected:
	int _counter;
	int _x;
	int _y;
	bool _remove;
};

#endif
