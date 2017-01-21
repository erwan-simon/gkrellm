#include <ncurses.h>
#include <string>
#include "textDisplay.hpp"

void	basicTemplate()
{
  while ()
    {

    }
}

void	header()
{
}

void		textDisplay()
{
  int	size[4];
  Infos	*infos = new Infos;
  
  size[0] = 0;
  size[1] = 0;
  initscr();
  noecho();
  while (1)
    {
      infos = updateInfos();
      getmaxyx(stdscr,size[2],size[3]);
      if (size[2] != size[0] || size[3] != size[1])
	{
	  basicTemplate();
	  size[0] = size[2];
	  size[1] = size[3];
	}
      header();
      refresh();
      getch();
    }
  endwin();
}
