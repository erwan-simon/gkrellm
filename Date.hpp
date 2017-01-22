//
// Date.hpp for  in /home/pe.merlier/Tek2/PiscineCpp/cpp_gkrellm
//
// Made by Pierre-Emmanuel Merlier
// Login   <pe.merlier@epitech.net>
//
// Started on  Sun Jan 22 05:44:53 2017 Pierre-Emmanuel Merlier
// Last update Sun Jan 22 06:28:07 2017 Pierre-Emmanuel Merlier
//

#ifndef DATE_HPP_
# define DATE_HPP_

#include <fstream>
#include <string>
#include <sys/utsname.h>
#include <iostream>
#include "IMonitorModule.hpp"

class Date : public IMonitorModule
{
private:
  std::string	_date;
  std::string	_time;
public:
  Date();
  virtual ~Date();
  Date &	operator=(Date const &);

  void		init(Info &);

  std::string	getDate() const;
  std::string	getTime() const;

  void		setDate(std::string);
  void		setTime(std::string);
};

#endif
