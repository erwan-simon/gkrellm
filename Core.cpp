//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sat Jan 21 17:24:05 2017 Pierre-Emmanuel Merlier
//

#include <string>
#include "Core.hpp"

static std::string PATH = "/proc/";

Core::Core()
{
  getLoadAvgFromFile();
  getCPUInfo();
  struct sysinfo info;
  if (!sysinfo(&info))
    {
      getRamInfo(info);
      getSwapInfo(info);
    }
  else
    {
      for (int i = 0; i < 2; i++)
	{
	  this->_ram[i] = 0;
	  this->_swap[i] = 0;
	}
    }
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

std::string Core::getCPUModel() const			{return (this->_CPUModel);}
int	Core::getCoreNb() const				{return (this->_coreNb);}
float	*Core::getCorePercent() const			{return (this->_corePercent);}
float	*Core::getRam() const				{return (this->_ram);}
float	*Core::getSwap() const				{return (this->_swap);}
int	*Core::getTasksNb() const			{return (this->_tasksNb);}
float	*Core::getLoadAvg() const			{return (this->_loadAvg);}

void	Core::setCPUModel(std::string model)		{this->_CPUModel = model;}
void	Core::setCoreNb(int coreNb)			{this->_coreNb = coreNb;}
void	Core::setCorePercent(float *corePercent)	{this->_corePercent = corePercent;}
void	Core::setRam(float *ram)			{this->_ram = ram;}
void	Core::setSwap(float *swap)			{this->_swap = swap;}
void	Core::setTasksNb(int *tasksNb)			{this->_tasksNb = tasksNb;}
void	Core::setLoadAvg(float *loadAvg)		{this->_loadAvg = loadAvg;}

void Core::getLoadAvgFromFile()
{
  int i = 0, j = 0;
  std::string src = PATH + "loadavg";
  std::string line, str;
  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      getline(file, line);
      while (j < 3)
	{
	  if (line[i] == ' ')
	    {
	      this->_loadAvg[j] = std::stof(str);
	      i++;
	      j++;
	      str = "";
	    }
	  str += line[i];
	  i++;
	}
    }
  else
    {
      for (int i = 0; i < 3; i++)
	this->_loadAvg[i] = 0;
    }
}

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

void Core::getCPUInfo()
{
  std::string src = PATH + "cpuinfo";
  std::string str, line;
  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      while (getline(file, line))
	str += line;
      this->_CPUModel = parsingCPU("model name", "stepping", str);
      this->_coreNb = stoi(parsingCPU("cpu cores", "apicid", str));
    }
  else
    {
      this->_CPUModel = "";
      this->_coreNb = 0;
    }
}

void Core::getRamInfo(struct sysinfo info)
{
  float total, free, use;
  total = (float)info.totalram / (1024 * 1024 * 1024);
  free = (float)info.freeram / (1024 * 1024 * 1024);
  use = total - free;
  this->_ram[0] = use;
  this->_ram[1] = total;
}

void Core::getSwapInfo(struct sysinfo info)
{
  float total, free, use;
  total = (float)info.totalswap / (1024 * 1024 * 1024);
  free = (float)info.freeswap / (1024 * 1024 * 1024);
  use = total - free;
  this->_swap[0] = use;
  this->_swap[1] = total;
}
