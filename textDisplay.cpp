#include <ncurses.h>
#include <string>
#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"
#include "textDisplay.hpp"

Infos&	updateInfos(Infos &infos)
{
  init_User(infos);
  infos._core.setCoreNb(4);
  return infos;
}

void	basicTemplate(Infos const &infos)
{
  int	a = 0;
  int	x = 1;
  int	y = 1;
  int	xMax;
  int	yMax;

  getmaxyx(stdscr, xMax, yMax);
  attron(COLOR_PAIR(1));
  mvprintw(0, y + ((yMax / 2) - 6) + 2, " ");
  attroff(COLOR_PAIR(1));
  while (a < infos._core.getCoreNb() + 2)
    {
      attron(COLOR_PAIR(2));
      if (a >= infos._core.getCoreNb())
	mvprintw(x + a, y, "%s[", (a == infos._core.getCoreNb() + 1 ? "Ram" : "Swp"));
      else
	mvprintw(x + a, y, "%d  [", a + 1);
      mvprintw(x + a, y + ((yMax / 2) - 6), "]");
      attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(1));
      mvprintw(x + a, y + ((yMax / 2) - 6) + 2, " ");
      attroff(COLOR_PAIR(1));
      a++;
    }
  attron(COLOR_PAIR(1));
  mvprintw(x + a, y + ((yMax / 2) - 6) + 2, " ");
  for (int i = 0; i <= yMax; i++)
    mvprintw(x + a + 1, y + i - 1, " ");
  attroff(COLOR_PAIR(1));
}

void	gauge(Infos const &infos)
{
  int	a = 0;
  int	xMax;
  int	yMax;
  int	i;
  float	f = 0.7;
  float f1 = 45.5;
  float f2 = 100.0;

  getmaxyx(stdscr, xMax, yMax);
  while (a < infos._core.getCoreNb())
    {
      attron(COLOR_PAIR(3));
      for (i = 5; i < ((yMax / 2) - 5); i++)
	mvprintw(a + 1, i, " ");
      attroff(COLOR_PAIR(3));
      attron(COLOR_PAIR(0));
      mvprintw(a + 1, 5, "5.4%%");
      attroff(COLOR_PAIR(0));
      a++;
    }
}

void		textDisplay()
{
  Infos		*infos = new Infos();
  int		size[4];

  size[0] = 0;
  size[1] = 0;
  initscr();
  noecho();
  start_color();
  use_default_colors();
  init_pair(0, COLOR_WHITE, -1);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_RED, -1);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  while (1)
    {
      updateInfos(*infos);
      getmaxyx(stdscr,size[2],size[3]);
      if (size[2] != size[0] || size[3] != size[1])
	{
	  basicTemplate(*infos);
	  size[0] = size[2];
	  size[1] = size[3];
	}
      gauge(*infos);
      refresh();
      getch();
    }
  endwin();
}
