//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sun Jan 22 06:27:04 2017 Pierre-Emmanuel Merlier
//

#ifndef RAM_HPP_
# define RAM_HPP_

#include <fstream>
#include <string>
#include <sys/sysinfo.h>
#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
public:
  RAM();
  virtual ~RAM();
  RAM&		operator=(RAM const &other);

public:
  void		init(Info &);

  float		*getRam() const;
  float		*getSwap() const;
  int		getNbTasks() const;
  float		*getLoadAvg() const;

  void		setRam(float *ram);
  void		setSwap(float *swap);
  void		setNbTasks(int tasksNb);
  void		setLoadAvg(float *loadAvg);
private:
  float		*_ram;
  float		*_swap;
  int		_nbTasks;
  float		*_loadAvg;
};

#endif
