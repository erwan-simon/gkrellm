//
// User.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 13:18:00 2017 erwan
// Last update Sun Jan 22 06:27:53 2017 Pierre-Emmanuel Merlier
//

#ifndef USER_HPP_
# define USER_HPP_

#include <string>
#include <fstream>
#include <sys/utsname.h>
#include <iostream>
#include "IMonitorModule.hpp"

class User : public IMonitorModule
{
public:
  User();
  virtual ~User();
  User&		operator=(User const &other);

public:
  void		init(Info &);

  std::string	getMachineName() const;
  std::string	getUserName() const;
  std::string	getOpSys() const;
  std::string	getKernel() const;

  void		setMachineName(std::string machineName);
  void		setUserName(std::string userName);
  void		setOpSys(std::string opSys);
  void		setKernel(std::string kernel);

private:
  std::string	_machineName;
  std::string	_userName;
  std::string	_opSys;
  std::string	_kernel;
};

#endif
