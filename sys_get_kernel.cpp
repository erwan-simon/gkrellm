//
// sys_get_kernel.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 15:50:49 2017 antoine
// Last update Sat Jan 21 15:59:39 2017 antoine
//

#include <sys/utsname.h>
#include <iostream>

void		sys_get_kernel()
{
  struct utsname	unameData;
  std::string		k_name = "ERROR";
  std::string		k_vers = "ERROR";
  
  if(uname(&unameData) != -1)
    {
      k_name = unameData.sysname;
      k_vers = unameData.version;
    }
  std::cout<<k_name<<std::endl;
  std::cout<<k_vers<<std::endl;
}
