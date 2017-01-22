//
// graphDisplay.hpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sun Jan 22 02:31:40 2017 antoine
// Last update Sun Jan 22 09:37:24 2017 antoine
//

#ifndef GRAPHDISPLAY_HPP_
# define GRAPHDISPLAY_HPP_

#include "Infos.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


void    graphDisplay(Infos &infos);
void	updateInfos(Infos &infos);

void    print_name(sf::RenderWindow *);
void    print_graphCPU4(sf::RenderWindow *, Infos const &);
void    print_graphCPU3(sf::RenderWindow *, Infos const &);
void    print_graphCPU2(sf::RenderWindow *, Infos const &);
void    print_graphCPU1(sf::RenderWindow *, Infos const &);
void    print_graphCPU(sf::RenderWindow *, Infos const &);
void    print_data(sf::RenderWindow *, Infos const &);
void    print_kernel(sf::RenderWindow *, Infos const &);
void    print_cpu(sf::RenderWindow *, Infos const &);
void    print_user(sf::RenderWindow *, Infos const &);

void    print_shape(sf::RenderWindow *, int, int);
void    print_title(sf::RenderWindow *, std::string, int);
void    print_text(sf::RenderWindow *, std::string, int);
void    print_shape2(sf::RenderWindow *, int, int, int, int, int);
void    print_title2(sf::RenderWindow *, std::string, int, int);
void    print_text2(sf::RenderWindow *, std::string, int, int);
#endif
