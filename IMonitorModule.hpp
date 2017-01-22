//
// IMonitorModule.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sun Jan 22 04:41:03 2017 erwan
// Last update Sun Jan 22 06:11:22 2017 erwan
//

#ifndef IMONITOR_HPP_
# define IMONITOR_HPP_

class IMonitorModule
{
public:
  virtual ~IMonitorModule();

  virtual void	init(Infos &infos) = 0;
};

#endif
