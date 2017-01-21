#include <ncurses.h>
#include <string>
#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"
#include "textDisplay.hpp"

void	updateInfos(Infos &infos)
{
  init_User(infos);
  infos._core.setCoreNb(4);
}

void	basicTemplate(Infos const &infos)
{
  int	a = 0;
  int	i;
  int	xMax;
  int	yMax;

  getmaxyx(stdscr, xMax, yMax);
  attron(COLOR_PAIR(1));
  for (i = 0; i < yMax; i++)
    mvprintw(0, i, " ");
  for (i = 0; i < 10; i++)
    mvprintw(i, 0, " ");
  for (i = 0; i < 10; i++)
    mvprintw(i, yMax - 1, " ");
  for (i = 1; i < 9; i++)
    mvprintw(i, 25, " ");
  for (i = 1; i < yMax; i++)
    mvprintw(9, i, " ");
  for (i = 1; i < 9; i++)
    mvprintw(i, (yMax / 2) + 23, " ");
  for (i = 1; i < 25; i++)
    mvprintw(3, i, " ");
  for (i = 1; i < 25; i++)
    mvprintw(1, i, " ");
  mvprintw(2, 11, " ");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  mvprintw(5, 2, "UserName: ");
  mvprintw(7, 2, "PCName: ");
  while (a < infos._core.getCoreNb() + 2)
    {
      if (a >= infos._core.getCoreNb())
	mvprintw(a + 2, 27, "%s[", (a == infos._core.getCoreNb() + 1 ? "Ram" : "Swp"));
      else
	mvprintw(a + 2, 27, "%d  [", a + 1);
      mvprintw(a + 2, (yMax / 2) + 21, "]");
      a++;
    }
  attroff(COLOR_PAIR(2));
}

void	gauge(Infos const &infos)
{
  (void) infos;
}

void	user(Infos const &infos)
{
  attron(COLOR_PAIR(0));
  mvprintw(5, 12, "%s", infos._user.getUserName().c_str());
  mvprintw(7, 12, "%s", infos._user.getMachineName().c_str());
  mvprintw();
  attroff(COLOR_PAIR(0));
}

void		textDisplay(Infos &infos)
{
  int		size[4];

  size[0] = 0;
  size[1] = 0;
  initscr();
  noecho();
  curs_set(0);
  start_color();
  keypad(stdscr, 1);
  use_default_colors();
  init_pair(0, COLOR_WHITE, -1);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_RED, -1);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  while (1)
    {
      updateInfos(infos);
      getmaxyx(stdscr,size[2],size[3]);
      if (size[2] != size[0] || size[3] != size[1])
	{
	  clear();
	  basicTemplate(infos);
	  size[0] = size[2];
	  size[1] = size[3];
	}
      user(infos);
      gauge(infos);
      refresh();
      getch();
    }
  curs_set(1);
  endwin();
}
