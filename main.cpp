//
// main.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 19:53:10 2017 antoine
// Last update Sat Jan 21 20:24:42 2017 antoine
//

#include <iostream>

#include "Infos.hpp"
#include "textDisplay.hpp"

void    help_mode()
{
  std::cout << "MyGKrellM 1.0.0 - (C) 2016 Epitech Rush 3/3 \n" << std::endl;
  std::cout << "-g		Display on the graphical interface"<< std::endl;
  std::cout << "-h --help	Print this help screen \n" << std::endl;
}

int	main(int ac, char ** av, char **env)
{
  Infos *infos = new Infos;
  if (ac == 1)
    textDisplay(*infos);
  else if ((std::string) av[1] == "-g")
    std::cout << "graphic" << std::endl;
      //   graphicDisplay(*infos);
    else
      help_mode();
  return (0);
}
