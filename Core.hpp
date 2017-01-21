//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sat Jan 21 22:40:19 2017 Pierre-Emmanuel Merlier
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <fstream>
#include <string>
#include <sys/sysinfo.h>

class		Core
{
public:
  Core();
  ~Core();
  Core&		operator=(Core const &other);

public:
  std::string	getCPUModel() const;
  int		getCoreNb() const;
  long long	*getCorePercent() const;
  float		*getRam() const;
  float		*getSwap() const;
  int		getNbTasks() const;
  float		*getLoadAvg() const;

  void		setCPUModel(std::string CPUModel);
  void		setCoreNb(int core);
  void		setCorePercent(long long *corePercent);
  void		setRam(float *ram);
  void		setSwap(float *swap);
  void		setNbTasks(int tasksNb);
  void		setLoadAvg(float *loadAvg);
private:
  std::string	_CPUModel;
  int		_coreNb;
  long long	*_corePercent; // tableau contenant dans l'ordre des cores leur pourcentage d'utilisation
  float		*_ram;
  float		*_swap;
  int		_nbTasks; // nb tache active
  float		*_loadAvg;
};

#endif
