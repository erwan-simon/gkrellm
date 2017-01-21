//
// Infos.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 12:29:09 2017 erwan
// Last update Sat Jan 21 17:24:06 2017 antoine
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

void    init_User(Infos &_info);
void    sys_get_hostname(Infos &_info);
void    sys_get_username(Infos &_info);
void    sys_get_kernel(Infos &_info);
void    sys_get_time(Infos &_info);

#endif
