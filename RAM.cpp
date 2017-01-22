//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sun Jan 22 06:26:31 2017 Pierre-Emmanuel Merlier
//

#include "RAM.hpp"
#include "Infos.hpp"

static std::string PATH = "/proc/";

/***** CONSTRUCTOR *****/
RAM::RAM()
{
}

RAM::~RAM()
{
}

/***** OPERATOR *****/
RAM&	RAM::operator=(RAM const &other)
{
  this->setRam(other.getRam());
  this->setSwap(other.getSwap());
  this->setNbTasks(other.getNbTasks());
  this->setLoadAvg(other.getLoadAvg());
  return (*this);
}

/***** GETTER *****/
float	*RAM::getRam() const				{return (this->_ram);}
float	*RAM::getSwap() const				{return (this->_swap);}
int	RAM::getNbTasks() const				{return (this->_nbTasks);}
float	*RAM::getLoadAvg() const			{return (this->_loadAvg);}

/***** SETTER *****/
void	RAM::setRam(float *ram)				{this->_ram = ram;}
void	RAM::setSwap(float *swap)			{this->_swap = swap;}
void	RAM::setNbTasks(int tasksNb)			{this->_nbTasks = tasksNb;}
void	RAM::setLoadAvg(float *loadAvg)			{this->_loadAvg = loadAvg;}

/***** INITIALISATION *****/
void RAM::init(Infos &info)
{
  float	res[2] = {0.0, 0.0};

  getLoadAvgFromFile(info);
  getNbTasksFromFile(info);
  getCPUInfo(info);
  getRAMPercentFromFile(info);
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
