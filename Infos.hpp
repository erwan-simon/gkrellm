//
// Infos.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 12:29:09 2017 erwan
// Last update Sat Jan 21 19:22:55 2017 Pierre-Emmanuel Merlier
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

void		init_User(Infos &_info);
void		sys_get_hostname(Infos &_info);
void		sys_get_username(Infos &_info);
void		sys_get_kernel(Infos &_info);
void		sys_get_time(Infos &_info);

void		init_Core(Infos &_info);
void		getCorePercentFromFile(Infos &);
void		getLoadAvgFromFile(Infos &);
void		getNbTasksFromFile(Infos &);
void		getCPUInfo(Infos &);
void		getRamInfo(struct sysinfo, Infos &);
void		getSwapInfo(struct sysinfo, Infos &);
std::string	parsingCPU(const std::string, const std::string, const std::string);
#endif
