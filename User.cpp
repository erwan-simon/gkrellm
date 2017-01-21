//
// User.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:22:34 2017 erwan
// Last update Sat Jan 21 17:54:34 2017 erwan
//

#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include <string>

#include "User.hpp"
#include "Infos.hpp"

User::User()
{
}

User::~User()
{
}

User&	User::operator=(User const &other)
{
  this->_machineName = other._machineName;
  this->_userName = other._userName;
  this->_opSys = other._opSys;
  this->_kernel = other._kernel;
  this->_date = other._date;
  this->_time = other._time;
  return (*this);
}

void          User::setMachineName(std::string machineName)	{this->_machineName = machineName;}
void          User::setUserName(std::string userName)		{this->_userName = userName;}
void          User::setOpSys(std::string opSys)			{this->_opSys = opSys;}
void          User::setKernel(std::string kernel)		{this->_kernel = kernel;}
void          User::setDate(std::string date)			{this->_date = date;}
void          User::setTime(std::string time)			{this->_time = time;}

std::string   User::getMachineName() const	{return (this->_machineName);}
std::string   User::getUserName() const		{return (this->_userName);}
std::string   User::getOpSys() const		{return (this->_opSys);}
std::string   User::getKernel() const		{return (this->_kernel);}
std::string   User::getDate() const		{return (this->_date);}
std::string   User::getTime() const		{return (this->_time);}

void	init_User(Infos &_info)
{
  sys_get_hostname(_info);
  sys_get_username(_info);
  sys_get_kernel(_info);
  sys_get_time(_info);
}

void    sys_get_hostname(Infos &_info)
{
  std::string   _src = "/proc/sys/kernel/hostname";
  std::ifstream _file(_src.c_str(), std::ios::in);
  std::string   _hostname = "ERROR";;

  if (_file)
    {
      if (!_file.eof())
	std::getline(_file, _hostname);
    }
  _file.close();
  _info._user.setMachineName(_hostname);
}

void	sys_get_username(Infos &_info)
{
  _info._user.setUserName("UserName");
}

void            sys_get_kernel(Infos &_info)
{
  struct utsname        unameData;
  std::string           k_name = "ERROR";
  std::string           k_vers = "ERROR";

  if(uname(&unameData) != -1)
    {
      k_name = unameData.sysname;
      k_vers = unameData.version;
    }
  _info._user.setOpSys(k_name);
  _info._user.setKernel(k_vers);
}

void    sys_get_time(Infos &_info)
{

  std::string   _src = "/proc/driver/rtc";
  std::ifstream _file(_src.c_str(), std::ios::in);
  std::string   _line;
  std::string _time = "ERROR";
  std::string _day = "ERROR";

  if (_file)
    {
      while(!_file.eof())
	{
	  std::getline(_file, _line);
	  if (_line.find("rtc_time") != _line.npos)
	    _time = _line.substr (11,19);
	  if (_line.find("rtc_date") != _line.npos)
	    _day = _line.substr (11,21);
	}
    }
  _file.close();
  _info._user.setTime(_time);
  _info._user.setDate(_day);
}
