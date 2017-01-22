//
// Date.cpp for  in /home/pe.merlier/Tek2/PiscineCpp/cpp_gkrellm
// 
// Made by Pierre-Emmanuel Merlier
// Login   <pe.merlier@epitech.net>
// 
// Started on  Sun Jan 22 05:50:26 2017 Pierre-Emmanuel Merlier
// Last update Sun Jan 22 06:29:06 2017 Pierre-Emmanuel Merlier
//

#include "Date.hpp"
#include "Infos.hpp"

Date::Date()
{
}

Date::~Date()
{
}

Date&	Date::operator=(Date const &other)
{
  this->_date = other._date;
  this->_time = other._time;
  return *this;
}

void		User::setDate(std::string date)	{this->_date = date;}
void		User::setTime(std::string time) {this->_time = time;}

std::string	User::getDate() const		{return (this->_date);}
std::string	User::getTime() const		{return (this->_time);}

void	Date::init(Infos & _info)
{
  sys_get_time(_info);
}

void    sys_get_time(Infos &_info)
{

  std::string   _src = "/proc/driver/rtc";
  std::ifstream _file(_src.c_str(), std::ios::in);
  std::string   _line;
  std::string	_time = "ERROR";
  std::string	_day = "ERROR";

  if (_file)
    {
      while(!_file.eof())
	{
	  std::getline(_file, _line);
	  if (_line.find("rtc_time") != _line.npos)
	    _time = _line.substr (11,19);
	  if (_line.find("rtc_date") != _line.npos)
	    _day = _line.substr (11,21);
	}
    }
  _file.close();
  _info._date.setTime(_time);
  _info._date.setDate(_day);
}
