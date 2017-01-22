//
// Network.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sun Jan 22 01:00:53 2017 erwan
// Last update Sun Jan 22 02:02:32 2017 erwan
//

#include <string>
#include <fstream>
#include <iostream>
#include "Network.hpp"
#include "Infos.hpp"

Network::Network()
{
}

void	Network::setUp(long long int up)
{
  this->_up = up;
}

void	Network::setDown(long long int down)
{
  this->_down = down;
}

long long int	Network::getUp() const
{
  return (this->_up);
}

long long int	Network::getDown() const
{
  return (this->_down);
}

Network::~Network()
{
}

void	init_Network(Infos &infos)
{
  std::string   src = "/proc/net/dev";
  std::string	line;
  std::ifstream file(src.c_str(), std::ios::in);
  int		max = 0;
  int		a = 0;
  int		i = 0;
  std::string	temp;

  while (std::getline(file, line))
    {
      if ((a = line.find(":")) != -1)
	{
	  a++;
	  while (line[a] == ' ')
	    a++;
	  while (line[a] != ' ')
	    {
	      temp += line[a];
	      a++;
	    }
	  // if (std::stoi(temp) > max)
	  //   {
	  //     infos._network.setUp(std::stoi(temp));
	  //     while (i != 7)
	  // 	{
	  // 	  while (line[a] >= '0' && line[a] <= '9')
	  // 	    {
	  // 	      while (1)
	  // 		std::cout << "salut" << std::endl;
	  // 	      a++;
	  // 	    }
	  // 	  while (line[a] <= '0' && line[a] >= '9')
	  // 	    a++;
	  // 	  i++;
	  // 	}
	  //     temp.erase();
	  //     while (line[a] < '0' && line[a] > '9')
	  // 	{
	  // 	  temp += line[a];
	  // 	  a++;
	  // 	}
	  //     std::cout << temp << std::endl;
	  //     infos._network.setDown(std::stoi(temp));
	  //     break ;
	  //   }
	}
    }
  file.close();
}  
