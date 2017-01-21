//
// sys_get_hostname.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 14:58:54 2017 antoine
// Last update Sat Jan 21 15:42:05 2017 antoine
//

#include <iostream>
#include <string>
#include <fstream>

void    sys_get_hostname()
{
  std::string	_src = "/proc/sys/kernel/hostname";
  std::ifstream _file(_src.c_str(), std::ios::in);
  std::string	_hostname = "ERROR";;

  if (_file)
    {
      if (!_file.eof())
	std::getline(_file, _hostname);
    }
  _file.close();
  std::cout << _hostname << std::endl;
}
