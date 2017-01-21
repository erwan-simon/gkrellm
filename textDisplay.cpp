#include <ncurses.h>
#include <string>
#include <ctime>
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
  int	h = 8 + (infos._core.getCoreNb() * 2);

  getmaxyx(stdscr, xMax, yMax);
  (void) xMax;
  attron(COLOR_PAIR(1));
  for (i = 0; i < yMax; i++)
    mvprintw(0, i, " ");
  for (i = 0; i < h; i++)
    mvprintw(i, 0, " ");
  for (i = 0; i < h; i++)
    mvprintw(i, yMax - 1, " ");
  for (i = 1; i < h; i++)
    mvprintw(i, 25, " ");
  for (i = 0; i < yMax; i++)
    mvprintw(h, i, " ");
  for (i = 1; i < h; i++)
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
  while (a < (infos._core.getCoreNb() * 2) + 4)
    {
      if (a >= (infos._core.getCoreNb() * 2))
	mvprintw(a + 4, 27, "%s[", (a == infos._core.getCoreNb() * 2 ? "Ram" : "Swp"));
      else
	mvprintw(a + 4, 27, "%d  [", (a / 2) + 1);
      mvprintw(a + 4, yMax - 35, "]");
      a += 2;
    }
  mvprintw(2, yMax - 31, "OS: ");
  mvprintw(4, yMax - 31, "Kernel: ");
  mvprintw(6, yMax - 31, "Core number: ");
  mvprintw(8, yMax - 31, "Active tasks: ");
  attroff(COLOR_PAIR(2));
}

void	gauge(Infos const &infos)
{
  int	xMax;
  int	yMax;
  int	i;
  int	a;
  getmaxyx(stdscr, xMax, yMax);
  unsigned int	totalLength = yMax - 31 - 35;
  int	length;
  float	*temp;

  (void) xMax;
  attron(COLOR_PAIR(3));
  temp = infos._core.getRam();
  length = (int) ((temp[0] * totalLength) / temp[1]);
  for (i = 0; i < length; i++)
    mvprintw(12, i + 31, " ");
  attroff(COLOR_PAIR(3));
  mvprintw(13, yMax - 46, "%.2fG/%.2fG", temp[0], temp[1]);

  attron(COLOR_PAIR(3));
  temp = infos._core.getSwap();
  length = (int) ((temp[0] * totalLength) / temp[0]);
  for (i = 0; i < length; i++)
    mvprintw(14, i + 31, " ");
  attroff(COLOR_PAIR(3));
  mvprintw(15, yMax - 46, "%.2fG/%.2fG", temp[0], temp[1]);

  srand(time(NULL));
  for (a = 0; a < infos._core.getCoreNb(); a++)
    {
      attron(COLOR_PAIR(3));
      // temp = infos._core.getCorePercent();
      temp[a] = rand() % 10001;
      temp[a] = temp[a] * 0.0001;
      length = (int) (((temp[a] * 100) * totalLength) / 100);
      for (i = 0; i < length; i++)
  	mvprintw(4 + (a * 2), i + 31, " ");
      attroff(COLOR_PAIR(3));
      attron(COLOR_PAIR(0));
      for (i = i; i < totalLength; i++)
	mvprintw(4 + (a * 2), i + 31, " ");
      attroff(COLOR_PAIR(0));
      mvprintw(5 + (a * 2), yMax - 40, "%.2f%%", temp[a]);
    }
}

void	user(Infos const &infos)
{
  int	xMax;
  int	yMax;

  (void) xMax;
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

  (void) xMax;
  getmaxyx(stdscr, xMax, yMax);
  attron(COLOR_PAIR(0));
  mvprintw(2, 33, "%s", infos._core.getCPUModel().c_str());
  mvprintw(6, yMax - 18, "%d", infos._core.getCoreNb());
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
