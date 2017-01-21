//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sat Jan 21 14:19:03 2017 erwan
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <string>

class		Core
{
public:
  Core();
  ~Core();
  Core&		operator=(Core const &other);

public:
  int		getCoreNb() const;
  float		*getCorePercent() const;
  float		*getRam() const;
  float		*getSwap() const;
  int		*getTasksNb() const;
  float		*getLoadAvg() const;
    
  void		setCoreNb(int core);
  void		setCorePercent(float *corePercent);
  void		setRam(float *ram);
  void		setSwap(float *swap);
  void		setTasksNb(int *tasksNb);
  void		setLoadAvg(float *loadAvg);
    
private:
  int		_coreNb;
  float		*_corePercent;
  float		*_ram;
  float		*_swap;
  int		*_tasksNb;
  float		*_loadAvg;
};

#endif
