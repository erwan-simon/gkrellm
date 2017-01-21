//
// User.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:22:34 2017 erwan
// Last update Sat Jan 21 14:48:50 2017 antoine
//

#include <string>
#include "User.hpp"

User::User()
{
}

Usera

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

void          setMachineName(std::string machineName)	{this->_machineName = machineName;}
void          setUserName(std::string userName)		{this->_userName = userName;}
void          setOpSys(std::string opSys)		{this->_opSys = opSys;}
void          setKernel(std::string kernel)		{this->_kernel = kernel;}
void          setDate(std::string date)			{this->_date = date;}
void          setTime(std::string time)			{this->_time = time;}

std::string   getMachineName() const	{return (this->_time);}
std::string   getUserName() const	{return (this->_userName);}
std::string   getOpSys() const		{return (this->_opSys);}
std::string   getKernel() const		{return (this->_kernel);}
std::string   getDate() const		{return (this->_date);}
std::string   getTime() const		{return (this->_time);}

