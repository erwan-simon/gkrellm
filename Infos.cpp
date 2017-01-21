//
// Infos.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:49:26 2017 erwan
// Last update Sat Jan 21 15:04:07 2017 erwan
//

#include <string>
#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"

Infos::Infos()
{
}

Infos::~Infos()
{
}

Infos&	Infos::operator=(Infos const &other)
{
  this->_core = other._core;
  this->_user = other._user;
  return (*this);
}
