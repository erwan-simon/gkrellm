//
// User.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:22:34 2017 erwan
// Last update Sat Jan 21 15:17:27 2017 erwan
//

#include <string>
#include "User.hpp"

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

std::string   User::getMachineName() const	{return (this->_time);}
std::string   User::getUserName() const		{return (this->_userName);}
std::string   User::getOpSys() const		{return (this->_opSys);}
std::string   User::getKernel() const		{return (this->_kernel);}
std::string   User::getDate() const		{return (this->_date);}
std::string   User::getTime() const		{return (this->_time);}

