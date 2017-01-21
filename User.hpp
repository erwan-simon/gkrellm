//
// User.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:18:00 2017 erwan
// Last update Sat Jan 21 13:18:55 2017 erwan
//

#ifndef USER_HPP_
# define USER_HPP_

#include <string>

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

  void		setMachineName();
  void		setUserName();
  void		setOpSys();
  void		setKernel();
  void		setDate();
  void		setTime();
  
private:
  std::string	_machineName;
  std::string	_userName;
  std::string	_opSys;
  std::string	_kernel;
  std::string	_date;
  std::string	_time;
};

#endif
