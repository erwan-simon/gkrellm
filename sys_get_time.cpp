//
// sys_get_time.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 14:58:04 2017 antoine
// Last update Sat Jan 21 14:58:04 2017 antoine
//

#include <iostream>
#include <string>
#include <fstream>

void	sys_get_time()
{
  std::ifstream _infile("/proc/driver/rtc");
  std::string _time;
  std::string _day;

if (_infile.good())
  {
    std::getline(_infile, _time);
    std::getline(_infile, _day);
  }
 _infile.close();
 _time = _time.substr (11,19);
 _day = _day.substr (11,21);
 std::cout << _time << std::endl; 
 std::cout << _day<< std::endl;
}
