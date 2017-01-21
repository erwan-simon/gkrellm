//
// name.cpp for  in /home/antoine/test
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 12:39:36 2017 antoine
// Last update Sat Jan 21 12:57:36 2017 antoine
//

#include <climits>
#include <unistd.h>
#include <iostream>

std::string	m_hostname()
{
  char name[HOST_NAME_MAX];

  gethostname(name, HOST_NAME_MAX);
  std::string	hostname(name);
  std::cout<<"Hostname : "<<hostname<<std::endl;
    
  return (name);
}

std::string	m_username()
{
  char name[LOGIN_NAME_MAX];

  getlogin_r(name, LOGIN_NAME_MAX);
  std::string	username(name);
  std::cout<<"Login : "<<username<<std::endl;
  
  return (username);
}


int main()
{
  m_hostname();
  m_username();
  return 0;
}
