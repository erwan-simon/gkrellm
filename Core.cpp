//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sat Jan 21 19:57:28 2017 erwan
//

#include <string>
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
void init_Core(Infos &_info)
{
  float	res[2] = {0.0, 0.0};
  
  getLoadAvgFromFile(_info);
  getCPUInfo(_info);
  struct sysinfo info;
  if (!sysinfo(&info))
    {
      getRamInfo(info, _info);
      getSwapInfo(info, _info);
    }
  else
    {
      _info._core.setRam(res);
      _info._core.setSwap(res);
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

// void Core::getCorePercentFromFile()
// {
  
// }

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

void getRamInfo(struct sysinfo info, Infos &_info)
{
  float total, free, use;
  float	res[2];
  
  total = (float)info.totalram / (1024 * 1024 * 1024);
  free = (float)info.freeram / (1024 * 1024 * 1024);
  use = total - free;
  res[0] = use;
  res[1] = total;
  _info._core.setRam(res);
}

void getSwapInfo(struct sysinfo info, Infos & _info)
{
  float total, free, use;
  float	res[2];
  
  total = (float)info.totalswap / (1024 * 1024 * 1024);
  free = (float)info.freeswap / (1024 * 1024 * 1024);
  use = total - free;
  res[0] = use;
  res[1] = total;
  _info._core.setSwap(res);
}
