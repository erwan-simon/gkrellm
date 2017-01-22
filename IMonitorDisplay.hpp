//
// IMonitorDisplay.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sun Jan 22 04:51:58 2017 erwan
// Last update Sun Jan 22 06:11:43 2017 erwan
//

#ifndef IMONITORDISPLAY_HPP_
# define IMONITORDISPLAY_HPP_

class IMonitorDisplay
{
public:
  virtual ~IMonitorDisplay();

  virtual void	displayCore(Infos &infos) = 0;
  virtual void	displayUser(Infos &infos) = 0;
  virtual void	displayNetwork(Infos &infos) = 0;
  
};

#endif
