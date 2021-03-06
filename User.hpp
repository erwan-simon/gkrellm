//
// User.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
//
// Made by erwan
// Login   <erwan.simon@epitech.eu>
//
// Started on  Sat Jan 21 13:18:00 2017 erwan
// Last update Sun Jan 22 06:59:23 2017 Pierre-Emmanuel Merlier
//

#ifndef USER_HPP_
# define USER_HPP_

#include <string>
#include "IMonitorModule.hpp"

class		User : public IMonitorModule
{
public:
  User();
  virtual ~User();
  User&		operator=(User const &other);

public:
  std::string	getMachineName() const;
  std::string	getUserName() const;
  std::string	getOpSys() const;
  std::string	getKernel() const;
  std::string	getDate() const;
  std::string	getTime() const;

  void		setMachineName(std::string machineName);
  void		setUserName(std::string userName);
  void		setOpSys(std::string opSys);
  void		setKernel(std::string kernel);
  void		setDate(std::string date);
  void		setTime(std::string time);

private:
  std::string	_machineName;
  std::string	_userName;
  std::string	_opSys; // operating system
  std::string	_kernel; // version du kernel
  std::string	_date;
  std::string	_time;
};

#endif
