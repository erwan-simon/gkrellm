#include <ncurses.h>
#include <string>
#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"
#include "textDisplay.hpp"

void	updateInfos(Infos &infos)
{
  init_User(infos);
  init_Core(infos);
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
  for (i = 0; i < 12; i++)
    mvprintw(i, 0, " ");
  for (i = 0; i < 12; i++)
    mvprintw(i, yMax - 1, " ");
  for (i = 1; i < 12; i++)
    mvprintw(i, 25, " ");
  for (i = 1; i < yMax; i++)
    mvprintw(11, i, " ");
  for (i = 1; i < 12; i++)
    mvprintw(i, yMax - 33, " ");
  for (i = 1; i < 25; i++)
    mvprintw(4, i, " ");
  for (i = 1; i < 4; i++)
    mvprintw(i, 12, " ");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  mvprintw(6, 2, "UserName: ");
  mvprintw(8, 2, "PCName: ");
  mvprintw(2, 27, "CPU: ");
  while (a < infos._core.getCoreNb() + 2)
    {
      if (a >= infos._core.getCoreNb())
	mvprintw(a + 4, 27, "%s[", (a == infos._core.getCoreNb() + 1 ? "Ram" : "Swp"));
      else
	mvprintw(a + 4, 27, "%d  [", a + 1);
      mvprintw(a + 4, yMax - 35, "]");
      a++;
    }
  mvprintw(2, yMax - 31, "OS: ");
  mvprintw(4, yMax - 31, "Kernel: ");
  mvprintw(8, yMax - 31, "Active tasks: ");
  attroff(COLOR_PAIR(2));
}

void	gauge(Infos const &infos)
{
  (void) infos;
}

void	user(Infos const &infos)
{
  int	xMax;
  int	yMax;

  getmaxyx(stdscr, xMax, yMax);
  attron(COLOR_PAIR(0));
  mvprintw(6, 12, "%s", infos._user.getUserName().c_str());
  mvprintw(8, 12, "%s", infos._user.getMachineName().c_str());
  mvprintw(2, 2, "%s", infos._user.getTime().c_str());
  mvprintw(2, 14, "%s", infos._user.getDate().c_str());
  mvprintw(2, yMax - 27, "%s", infos._user.getOpSys().c_str());
  mvprintw(4, yMax - 23, "%s", infos._user.getKernel().c_str());
  attroff(COLOR_PAIR(0));
}

void	core(Infos const &infos)
{
  int	xMax;
  int	yMax;

  getmaxyx(stdscr, xMax, yMax);
  attron(COLOR_PAIR(0));
  mvprintw(2, 33, "%s", infos._core.getCPUModel().c_str());
  mvprintw(8, yMax - 17, "%d", infos._core.getNbTasks());
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
      core(infos);
      gauge(infos);
      refresh();
    }
  curs_set(1);
  endwin();
}
