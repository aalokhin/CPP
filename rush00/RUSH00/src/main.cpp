#include <ncurses.h>
#include <iostream>
#include <list>
#include <typeinfo>
#include "Player.hpp"
#include "Creep.hpp"
#include "Shot.hpp"
#include "NCurses.hpp"
#include "NAList.hpp"
#include <sstream>
#include <string.h>
#include <string>

int main(void)
{
	NCurses nCurses;
	env(&nCurses);

	bool shouldQuit = false; 
	int ch;

	NAList entities;
	int counter = 0;
	int kills = 0;

	Player p;
	entities.add(&p);
	p.setPosition(LINES / 2, COLS / 2 + 1);
	
	bool lost = false;
	WINDOW * win = newwin(3, 10, LINES / 2 - 2, COLS / 2 - 5);

	if (!has_colors())
	{
		endwin();
		//printf("\nОшибка! Не поддерживаются цвета\n");
		return 1;
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);	
	wbkgdset(win, COLOR_PAIR(1));
	wrefresh(win);
	//string s;
	//mvwprintw(win, LINES / 2, COLS / 2, s.push_back((char)('0' + kills)););
	while (!shouldQuit) {
		while ((ch = getch()) != ERR)
		{
			if (ch == 'q')
				shouldQuit = true;

			if (ch == 'd')
				p.setX(p.getX() + 1);
			if (ch == 'a')
				p.setX(p.getX() - 1);

			if (ch == 's')
				p.setY(p.getY() + 1);
			if (ch == 'w')
				p.setY(p.getY() - 1);

			if (ch == ' ')
			{
				entities.add(new Shot(p.getY(), p.getX()));
			}
		}

		counter++;
		if (counter >= 400)
		{
			entities.add(new Creep());
			counter = 0;
		}

		clear();

		if (!lost)
		{
			IEntity **raw = entities.getArray();
			for (size_t i = 0; i < entities.getHigh(); i++)
			{
				IEntity *ptr = raw[i];

				if (ptr == NULL)
					continue;

				ptr->update();

				if (ptr->shouldRemove())
				{
					entities.remove(i);
					continue;
				}
				else
				{
					for (size_t c = 0; c < entities.getHigh(); c++)
					{
						IEntity *cptr = raw[c];

						if (cptr == NULL || cptr == ptr)
							continue;

						if (cptr->collide(*ptr))
						{
							entities.remove(c);
							entities.remove(i);
							kills++;
							//printw(kills);
							ptr = NULL;
							break;
						}
						else if (cptr->checkCollide(*ptr) &&
							typeid(*ptr) == typeid(Player) &&
							typeid(*cptr) == typeid(Creep))
						{
							lost = true;
						}
					}
				}

				if (ptr == NULL)
					continue;
				ptr->render();
			}
		}
		box(win, 0, 0);
		wmove(win, 1, 1);
		waddstr(win, "YOU DIE");
	
		//waddstr(win, "kills");
		//stringstream convert;
		//convert << i;
		//waddstr(win, convert.str().c_str());
		refresh();
		if (lost)
			wrefresh(win);

		napms(2);
	}
	return 0;
}
