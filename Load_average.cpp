//
// test2.cpp for  in /home/antoine/test
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 11:20:54 2017 antoine
// Last update Sat Jan 21 11:28:56 2017 antoine
//

#include <iostream>
#include <fstream>

int main()
{
  int i = 1;
  while(i != 0)
    {
      std::ifstream f("/proc/loadavg");
      if (f.is_open())
	std::cout << f.rdbuf();
    }
}
