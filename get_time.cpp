//
// get_time.cpp for  in /home/antoine/test
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sat Jan 21 12:25:11 2017 antoine
// Last update Sat Jan 21 12:35:40 2017 antoine
//

#include <ctime>
#include <string>
#include <iostream>

const std::string currentDate() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[11];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
  return buf;
}

const std::string currentTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[9];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%X", &tstruct);
  return buf;
}

int main() {
  std::cout << "currentDate : " << currentDate() << std::endl;
  std::cout << "currentTime : " << currentTime() << std::endl;
}
