//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sat Jan 21 14:46:37 2017 erwan
//

#include <string>
#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

Core&	Core::operator=(Core const &other)
{
  this->setCoreNb(other.getCoreNb());
  this->setCorePercent(other.getCorePercent());
  this->setRam(other.getRam());
  this->setSwap(other.getSwap());
  this->setTasksNb(other.getTasksNb());
  this->setLoadAvg(other.getLoadAvg());
  return (*this);
}

int	Core::getCoreNb() const				{return (this->_coreNb);}
float	*Core::getCorePercent() const			{return (this->_corePercent);}
float	*Core::getRam() const				{return (this->_ram);}
float	*Core::getSwap() const				{return (this->_swap);}
int	*Core::getTasksNb() const			{return (this->_tasksNb);}
float	*Core::getLoadAvg() const			{return (this->_loadAvg);}

void	Core::setCoreNb(int coreNb)			{this->_coreNb = coreNb;}
void	Core::setCorePercent(float *corePercent)	{this->_corePercent = corePercent;}
void	Core::setRam(float *ram)			{this->_ram = ram;}
void	Core::setSwap(float *swap)			{this->_swap = swap;}
void	Core::setTasksNb(int *tasksNb)			{this->_tasksNb = tasksNb;}
void	Core::setLoadAvg(float *loadAvg)		{this->_loadAvg = loadAvg;}
