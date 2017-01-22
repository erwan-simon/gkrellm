//
// Infos.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 12:29:09 2017 erwan
// Last update Sun Jan 22 06:30:36 2017 Pierre-Emmanuel Merlier
//

#ifndef INFOS_HPP_
# define INFOS_HPP_

#include <string>
#include <fstream>
#include "Core.hpp"
#include "User.hpp"
#include "Network.hpp"

class	Infos
{
public:
  Infos();
  ~Infos();
  Infos&	operator=(Infos const &other);

public:
  Core		_core;
  User		_user;
  Network	_network;
};

void		sys_get_hostname(Infos &_info);
void		sys_get_username(Infos &_info);
void		sys_get_kernel(Infos &_info);

void		sys_get_time(Infos &_info);

void		getCorePercentFromFile(Infos &);
float		getCPUIdle(std::string);
float		getCPUNonIdle(std::string);
float		*fillCPUNonIdle(std::string);
float		*fillCPUIdle(std::string);

void		getLoadAvgFromFile(Infos &);
void		getNbTasksFromFile(Infos &);
void		getCPUInfo(Infos &);
void		getRamInfo(struct sysinfo, Infos &);
void		getSwapInfo(struct sysinfo, Infos &);
std::string	parsingCPU(const std::string, const std::string, const std::string);

void		init_Network(Infos &);
void		display(Infos &);

#endif
