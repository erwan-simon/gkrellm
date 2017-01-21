//
// User.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:18:00 2017 erwan
// Last update Sat Jan 21 16:38:10 2017 antoine
//

#ifndef USER_HPP_
# define USER_HPP_

#include <string>
#include "Infos.hpp"

class		User
{
public:
  User();
  ~User();
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

void    init_User(Infos &_info);
void    sys_get_hostname(Infos &_info);
void    sys_get_kernel(Infos &_info);
void    sys_get_time(Infos &_info);

#endif
