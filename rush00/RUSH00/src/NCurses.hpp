#ifndef NCURSES_CLASS_H
# define NCURSES_CLASS_H

# include <cstddef>

class NCurses
{
public:
	NCurses(void);
	NCurses(NCurses const &);
	~NCurses(void);

	NCurses& operator=(NCurses const &);

	void setSize(int y, int x);
	int getX(void);
	int getY(void);
private:
	int _x;
	int _y;
};

NCurses* env(NCurses *c = NULL);

#endif
