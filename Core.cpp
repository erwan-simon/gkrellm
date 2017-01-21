//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sat Jan 21 18:36:26 2017 Pierre-Emmanuel Merlier
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
  this->setNbActivTasks(other.getNbActivTasks());
  this->setLoadAvg(other.getLoadAvg());
  return (*this);
}

/***** GETTER *****/
std::string Core::getCPUModel() const			{return (this->_CPUModel);}
int	Core::getCoreNb() const				{return (this->_coreNb);}
float	*Core::getCorePercent() const			{return (this->_corePercent);}
float	*Core::getRam() const				{return (this->_ram);}
float	*Core::getSwap() const				{return (this->_swap);}
int	Core::getNbActivTasks() const			{return (this->_nbActivTasks);}
float	*Core::getLoadAvg() const			{return (this->_loadAvg);}

/***** SETTER *****/
void	Core::setCPUModel(std::string model)		{this->_CPUModel = model;}
void	Core::setCoreNb(int coreNb)			{this->_coreNb = coreNb;}
void	Core::setCorePercent(float *corePercent)	{this->_corePercent = corePercent;}
void	Core::setRam(float *ram)			{this->_ram = ram;}
void	Core::setSwap(float *swap)			{this->_swap = swap;}
void	Core::setNbActivTasks(int tasksNb)		{this->_nbActivTasks = tasksNb;}
void	Core::setLoadAvg(float *loadAvg)		{this->_loadAvg = loadAvg;}

/***** INITIALISATION *****/
void init_Core(Infos &_info)
{
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
      for (int i = 0; i < 2; i++)
	{
	  _info._core._ram[i] = 0;
	  _info._core._swap[i] = 0;
	}
    }
}

/***** FUNCTIONS *****/
void  getLoadAvgFromFile(Infos & info)
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
	      info._core._loadAvg[j] = std::stof(str);
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
	info._core._loadAvg[i] = 0;
    }
}

void Core::getCorePercentFromFile()
{
  
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

void getCPUInfo(Infos & info)
{
  std::string src = PATH + "cpuinfo";
  std::string str, line;
  std::ifstream file(src.c_str(), std::ios::in);
  if (file)
    {
      while (getline(file, line))
	str += line;
      info._core._CPUModel = parsingCPU("model name", "stepping", str);
      info._core._coreNb = stoi(parsingCPU("cpu cores", "apicid", str));
    }
  else
    {
      info._core._CPUModel = "";
      info._core._coreNb = 0;
    }
}

void getRamInfo(struct sysinfo info, Infos &_info)
{
  float total, free, use;
  total = (float)info.totalram / (1024 * 1024 * 1024);
  free = (float)info.freeram / (1024 * 1024 * 1024);
  use = total - free;
  _info._core._ram[0] = use;
  _info._core._ram[1] = total;
}

void getSwapInfo(struct sysinfo info, Infos & _info)
{
  float total, free, use;
  total = (float)info.totalswap / (1024 * 1024 * 1024);
  free = (float)info.freeswap / (1024 * 1024 * 1024);
  use = total - free;
  _info._core._swap[0] = use;
  _info._core._swap[1] = total;
}
int main() {}
