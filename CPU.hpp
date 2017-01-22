//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sun Jan 22 06:27:32 2017 Pierre-Emmanuel Merlier
//

#ifndef CPU_HPP_
# define CPU_HPP_

#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
private:
  std::string	_CPUModel;
  int		_coreNb;
  float		*_corePercent;
public:
  CPU();
  virtual ~CPU();
  CPU&		operator=(CPU const &other);

  void		init(Info &);

  std::string	getCPUModel() const;
  int		getCoreNb() const;
  float		*getCorePercent() const;

  void		setCPUModel(std::string);
  void		setCoreNb(int);
  void		setCorePercent(float *);
};

#endif
