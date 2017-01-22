//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sun Jan 22 02:44:34 2017 Pierre-Emmanuel Merlier
//

#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "Core.hpp"
#include "Infos.hpp"

static std::string PATH = "/proc/";


/***** CONSTRUCTOR *****/
Core::Core()
{
}

Core::~Core()
{
}

/***** OPERATOR *****/
Core&	Core::operator=(Core const &other)
{
  this->setCoreNb(other.getCoreNb());
  this->setCorePercent(other.getCorePercent());
  this->setRam(other.getRam());
  this->setSwap(other.getSwap());
  this->setNbTasks(other.getNbTasks());
  this->setLoadAvg(other.getLoadAvg());
  return (*this);
}

/***** GETTER *****/
std::string Core::getCPUModel() const			{return (this->_CPUModel);}
int	Core::getCoreNb() const				{return (this->_coreNb);}
float	*Core::getCorePercent() const			{return (this->_corePercent);}
float	*Core::getRam() const				{return (this->_ram);}
float	*Core::getSwap() const				{return (this->_swap);}
int	Core::getNbTasks() const			{return (this->_nbTasks);}
float	*Core::getLoadAvg() const			{return (this->_loadAvg);}

/***** SETTER *****/
void	Core::setCPUModel(std::string model)		{this->_CPUModel = model;}
void	Core::setCoreNb(int coreNb)			{this->_coreNb = coreNb;}
void	Core::setCorePercent(float *corePercent)	{this->_corePercent = corePercent;}
void	Core::setRam(float *ram)			{this->_ram = ram;}
void	Core::setSwap(float *swap)			{this->_swap = swap;}
void	Core::setNbTasks(int tasksNb)			{this->_nbTasks = tasksNb;}
void	Core::setLoadAvg(float *loadAvg)		{this->_loadAvg = loadAvg;}

/***** INITIALISATION *****/
void init_Core(Infos &info)
{
  float	res[2] = {0.0, 0.0};

  getLoadAvgFromFile(info);
  getNbTasksFromFile(info);
  getCPUInfo(info);
  getCorePercentFromFile(info);
  struct sysinfo sys;
  if (!sysinfo(&sys))
    {
      getRamInfo(sys, info);
      getSwapInfo(sys, info);
    }
  else
    {
      info._core.setRam(res);
      info._core.setSwap(res);
    }
}

/***** FUNCTIONS *****/
std::string parsingCPU(const std::string find, const std::string end,
		      const std::string str)
{
  int i, j;
  std::string ret;
  i = str.find(find);
  j = str.find(end);
  while (str[i] != ':')
    i++;
  i+=2;
  while (i < j)
    ret += str[i++];
  return (ret);
}

void  getLoadAvgFromFile(Infos & info)
{
  int i = 0, j = 0;
  std::string src = PATH + "loadavg";
  std::string line, str;
  std::ifstream file(src.c_str(), std::ios::in);
  float	res[3] = {0.0, 0.0, 0.0};

  if (file)
    {
      getline(file, line);
      while (j < 3)
	{
	  if (line[i] == ' ')
	    {
	      res[j] = std::stof(str);
	      i++;
	      j++;
	      str = "";
	    }
	  str += line[i];
	  i++;
	}
      info._core.setLoadAvg(res);
    }
  else
    info._core.setLoadAvg(res);
}

void  getNbTasksFromFile(Infos & info)
{
  int i = 0;
  std::string src = PATH + "loadavg";
  std::string line, str;
  std::ifstream file(src.c_str(), std::ios::in);

  if (file)
    {
      getline(file, line);
      while (line[i] != '/')
	{
	  i++;
	}
      str += line[i-1];
      info._core.setNbTasks(std::stoi(str));
    }
  else
    {
      info._core.setNbTasks(0);
    }
}

#include <iostream>
//CPUPercentage
float getCPUIdle(std::string line)
{
  int k = 0;
  unsigned int i = 0;
  float idle = 0;
  std::string nb;

  while (i < line.length())
    {
      if (line[i] >= '0' && line[i] <= '9')
	{
	  while (line[i] >= '0' && line[i] <= '9')
	    nb += line[i++];
	  if (k == 3 | k == 4)
	    idle += std::stof(nb);
	  k++;
	  nb = "";
	}
      i++;
    }
  return idle;
}

float getCPUNonIdle(std::string line)
{
  int k = 0;
  unsigned int i = 0;
  float nonIdle = 0;
  std::string nb;

  while (i < line.length())
    {
      if (line[i] >= '0' && line[i] <= '9')
	{
	  while (line[i] >= '0' && line[i] <= '9')
	    nb += line[i++];
	  if (k != 3 && k != 4)
	    nonIdle += std::stof(nb);
	  nb = "";
	  k++;
	}
      i++;
    }
  return nonIdle;
}

float *fillCPUIdle(std::string src)
{
  int i, jump = 0, li = 0;
  float *ret = new float;
  std::string line;

  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      while (getline(file, line))
	{
	  i = line.find("cpu");
	  if (i != -1 && jump != 0)
	    {
	      switch (li++)
		{
		case 0:
		  ret[0] = getCPUIdle(line);
		  break;
		case 1:
		  ret[1] = getCPUIdle(line);
		  break;
		case 2:
		  ret[2] = getCPUIdle(line);
		  break;
		case 3:
		  ret[3] = getCPUIdle(line);
		  break;
		}
	    }
	  jump = 1;
	}
    }

  file.close();
  return (ret);
}

float *fillCPUNonIdle(std::string src)
{
  int i, jump = 0, li = 0;
  float *ret = new float;
  std::string line;

  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      while (getline(file, line))
	{
	  i = line.find("cpu");
	  if (i != -1 && jump != 0)
	    {
	      switch (li++)
		{
		case 0:
		  ret[0] = getCPUNonIdle(line);
	      break;
		case 1:
		  ret[1] = getCPUNonIdle(line);
	      break;
		case 2:
		  ret[2] = getCPUNonIdle(line);
		  break;
		case 3:
		  ret[3] = getCPUNonIdle(line);
		  break;
		}
	    }
	  jump = 1;
	}
    }

  file.close();
  return (ret);
}

void getCorePercentFromFile(Infos & info)
{
  std::string src = PATH + "stat";
  float *ret = new float;
  float *prevIdle, *idle;
  float *prevNonIdle, *nonIdle;
  float *prevTotal = new float;
  float *total = new float;
  float *totald = new float;
  float *idled = new float;

  prevIdle = fillCPUIdle(src);
  prevNonIdle = fillCPUNonIdle(src);

  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  idle = fillCPUIdle(src);
  nonIdle = fillCPUNonIdle(src);

  int i = 0;
  while (i < 4)
    {
      prevTotal[i] = prevIdle[i] + prevNonIdle[i];
      total[i] = idle[i] + nonIdle[i];

      totald[i] = nonIdle[i] - prevNonIdle[i];
      idled[i] = idle[i] - prevIdle[i];

      ret[i] = (totald[i] / (totald[i] + idled[i])) * 100;
      i++;
    }
  info._core.setCorePercent(ret);
}
//!CPU

void getCPUInfo(Infos & info)
{
  std::string src = PATH + "cpuinfo";
  std::string str, line;
  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      while (getline(file, line))
	str += line;
      info._core.setCPUModel(parsingCPU("model name", "stepping", str));
      info._core.setCoreNb(std::stoi(parsingCPU("cpu cores", "apicid", str)));
    }
  else
    {
      info._core.setCPUModel("");
      info._core.setCoreNb(0);
    }
}

void getRamInfo(struct sysinfo sys, Infos &info)
{
  float total, free, use;
  float	*ram = new float;

  total = (float)sys.totalram / (1024 * 1024 * 1024);
  free = (float)sys.freeram / (1024 * 1024 * 1024);
  use = total - free;
  ram[0] = use;
  ram[1] = total;
  info._core.setRam(ram);
}

void getSwapInfo(struct sysinfo sys, Infos & info)
{
  float total, free, use;
  float	*swap = new float;

  total = (float)sys.totalswap / (1024 * 1024 * 1024);
  free = (float)sys.freeswap / (1024 * 1024 * 1024);
  use = total - free;
  swap[0] = use;
  swap[1] = total;
  info._core.setSwap(swap);
}
