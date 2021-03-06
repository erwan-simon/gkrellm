//
// main.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 19:53:10 2017 antoine
// Last update Sun Jan 22 03:32:46 2017 antoine
//

#include <iostream>

#include "Infos.hpp"
#include "textDisplay.hpp"
#include "graphDisplay.hpp"

void    updateInfos(Infos &infos)
{
  init_User(infos);
  init_Core(infos);
  init_Network(infos);
  infos._core.setCoreNb(4);
}

void    help_mode()
{
  std::cout << "MyGKrellM 1.0.0 - (C) 2016 Epitech Rush 3/3 \n" << std::endl;
  std::cout << "-g		Display on the graphical interface"<< std::endl;
  std::cout << "-h --help	Print this help screen \n" << std::endl;
}

std::string     my_getenv(char **env)
{
  std::string   line;
  int		size = 0;
  std::string   name = "ERROR";
  int   i = 0;

  while (env[i] != NULL)
    {
      line = env[i];
      if (line.find("USER=") != line.npos)
	{
	  size = line.length();
	  name = line.substr(5 , size);
	}
      i++;
    }
  return name;
}

int		main(int ac, char ** av, char **env)
{
  Infos		*infos = new Infos;
  std::string	user_name = my_getenv(env);

  infos->_user.setUserName(user_name);
  if (ac == 1)
    textDisplay(*infos);
  else if ((std::string) av[1] == "-g")
    graphDisplay(*infos);
  else
    help_mode();
  delete infos;
  return (0);
}
