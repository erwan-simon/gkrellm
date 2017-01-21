//
// sys_get_hostname.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 14:58:54 2017 antoine
// Last update Sat Jan 21 14:59:13 2017 antoine
//

#include <iostream>
#include <string>
#include <fstream>

void    sys_get_hostname()
{
  std::ifstream _infile("/proc/sys/kernel/hostname");
  std::string	_hostname;

  if (_infile.good())
    {
      std::getline(_infile, _hostname);
    }
  _infile.close();
  std::cout << _hostname << std::endl;
}
