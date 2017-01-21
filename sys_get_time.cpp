//
// sys_get_time.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 14:58:04 2017 antoine
// Last update Sat Jan 21 15:42:12 2017 antoine
//

#include <iostream>
#include <string>
#include <fstream>

void	sys_get_time()
{

  std::string	_src = "/proc/driver/rtc";
  std::ifstream _file(_src.c_str(), std::ios::in);
  std::string	_line;
  std::string _time = "ERROR";
  std::string _day = "ERROR";

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
  std::cout << _time << std::endl; 
  std::cout << _day<< std::endl;
}
