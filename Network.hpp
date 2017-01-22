//
// Network.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sun Jan 22 01:01:27 2017 erwan
// Last update Sun Jan 22 01:11:30 2017 erwan
//

#ifndef NETWORKING_HPP_
# define NETWORKING_HPP_

#include <string>

class Network {
public:
  Network();
  ~Network();

  void		setUp(long long int up);
  void		setDown(long long int down);

  long long int	getUp() const;
  long long int	getDown() const;
  
private:
  long long int	_up;
  long long int	_down;
};

#endif
