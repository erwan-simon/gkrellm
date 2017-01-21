//
// Infos.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 12:29:09 2017 erwan
// Last update Sat Jan 21 14:57:01 2017 erwan
//

#ifndef INFOS_HPP_
# define INFOS_HPP_

#include <string>
#include "Core.hpp"
#include "User.hpp"

class	Infos
{
public:
  Infos();
  ~Infos();
  Infos&	operator=(Infos const &other);

public:
  Core		_core;
  User		_user;
};


#endif
