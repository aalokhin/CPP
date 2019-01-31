#include <ncurses.h>
#include <csignal>
#include "NCurses.hpp"

NCurses* env(NCurses *c)
{
	static NCurses* ptr;

	if (c)
		ptr = c;
	return ptr;
}

void	onResize(int)
{
	endwin();
	refresh();
	clear();

	int x, y;
	getmaxyx(stdscr, y, x);
	env()->setSize(y, x);
}

NCurses::NCurses(void) : _x(0), _y(0)
{
	initscr(); 
	cbreak(); 
	noecho(); 

	curs_set(0);

				 
	keypad(stdscr, TRUE); 
	nodelay(stdscr, TRUE); 
	scrollok(stdscr, FALSE); 

							 
	getmaxyx(stdscr, this->_y, this->_x);

	std::signal(SIGWINCH, onResize); 
}


NCurses::~NCurses(void)
{
	endwin();
}

void NCurses::setSize(int y, int x)
{
	this->_y = y;
	this->_x = x;
}

int NCurses::getX(void)
{
	return this->_x;
}

int NCurses::getY(void)
{
	return this->_y;
}

NCurses::NCurses(NCurses const &) {}
NCurses& NCurses::operator=(NCurses const &) { return *this; }
