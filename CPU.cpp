//
// Core.cpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 14:06:57 2017 erwan
// Last update Sun Jan 22 06:29:23 2017 Pierre-Emmanuel Merlier
//

#include "CPU.hpp"
#include "Infos.hpp"

static std::string PATH = "/proc/";


/***** CONSTRUCTOR *****/
CPU::CPU()
{
}

CPU::~CPU()
{
}

/***** OPERATOR *****/
CPU&	CPU::operator=(CPU const &other)
{
  this->setCPUModel(other.getCPUModel());
  this->setCoreNb(other.getCPUNb());
  this->setCorePercent(other.getCPUPercent());
  return (*this);
}

/***** GETTER *****/
std::string CPU::getCPUModel() const			{return (this->_CPUModel);}
int	CPU::getCoreNb() const				{return (this->_coreNb);}
float	*CPU::getCorePercent() const			{return (this->_corePercent);}

/***** SETTER *****/
void	CPU::setCPUModel(std::string model)		{this->_CPUModel = model;}
void	CPU::setCoreNb(int coreNb)			{this->_coreNb = coreNb;}
void	CPU::setCorePercent(float *corePercent)		{this->_corePercent = corePercent;}

/***** INITIALISATION *****/
void CPU::init(Infos &info)
{
  float	res[2] = {0.0, 0.0};

  getLoadAvgFromFile(info);
  getNbTasksFromFile(info);
  getCPUInfo(info);
  getCPUPercentFromFile(info);
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

void getCPUPercentFromFile(Infos & info)
{
  std::string src = PATH + "stat";
  float *ret = new float;
  float *prevIdle, *idle;
  float *prevNonIdle, *nonIdle;
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
      totald[i] = nonIdle[i] - prevNonIdle[i];
      idled[i] = idle[i] - prevIdle[i];

      ret[i] = (totald[i] / (totald[i] + idled[i])) * 100;
      i++;
    }
  info._core.setCPUPercent(ret);
  delete (prevIdle);
  delete (idle);
  delete (prevNonIdle);
  delete (nonIdle);
  delete (totald);
  delete (idled);
}

std::string parsingCPU(const std::string str)
{
  unsigned int i = 0;
  std::string ret;
  while (str[i] != ':')
    i++;
  i+=2;
  while (i < str.length())
    ret += str[i++];
  return (ret);
}

void getCPUInfo(Infos & info)
{
  std::string src = PATH + "cpuinfo";
  std::string str, line;
  std::ifstream file(src.c_str(), std::ios::in);
  info._core.setCPUNb(0);
  if (file)
    {
      while (getline(file, line))
	{
	  if (line.find("model name") != -1)
	    info._core.setCPUModel(parsingCPU(line));
	  else if (line.find("processor") != -1)
	    info._core.setCPUNb(info._core.getCPUNb() + 1);
	}
    }
  else
    {
      info._core.setCPUModel("");
      info._core.setCPUNb(0);
    }
}
