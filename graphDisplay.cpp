//
// graphDisplay.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sun Jan 22 02:30:51 2017 antoine
// Last update Sun Jan 22 07:46:12 2017 antoine
//

#include <iostream>
#include <string>
#include <sstream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"
#include "graphDisplay.hpp"

void    print_shape(sf::RenderWindow *window, int _x, int _size)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(280, _size));
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(3);
  rectangle.setPosition(10, _x);
  window->draw(rectangle);
}

void    print_title(sf::RenderWindow *window, std::string _text, int _x)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text text;
  text.setFont(font);
  text.setString(_text);
  text.setCharacterSize(14);
  text.setColor(sf::Color::Red);
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width/2.0f,
		 textRect.top  + textRect.height/2.0f);
  text.setPosition(sf::Vector2f(300/2.0f, _x));
  window->draw(text);
}

void    print_text(sf::RenderWindow *window, std::string _text, int _x)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text text;
  text.setFont(font);
  text.setString(_text);
  text.setCharacterSize(12);
  text.setColor(sf::Color::Black);
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width/2.0f,
		 textRect.top  + textRect.height/2.0f);
  text.setPosition(sf::Vector2f(300/2.0f, _x));
  window->draw(text);
}

void    print_shape2(sf::RenderWindow *window, int _x, int _y, int _sizex, int _sizey, int value)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(_sizey, _sizex));
  rectangle.setOutlineColor(sf::Color::Black);
  if (value == 0)
    rectangle.setFillColor(sf::Color::White);
  else if (value <= 10 && value != 0)
    rectangle.setFillColor(sf::Color::Blue);
  else if (value <= 25 && value > 10)
    rectangle.setFillColor(sf::Color::Green);
  else if (value < 50 && value > 25)
    rectangle.setFillColor(sf::Color::Yellow);
  else
    rectangle.setFillColor(sf::Color::Red);
  rectangle.setOutlineThickness(3);
  rectangle.setPosition(_y, _x);
  window->draw(rectangle);
}

void    print_title2(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text text;
  text.setFont(font);
  text.setString(_text);
  text.setCharacterSize(14);
  text.setColor(sf::Color::Red);
  text.setPosition(_y, _x);
  window->draw(text);
}

void    print_text2(sf::RenderWindow *window, std::string _text, int _x, int _y)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text text;
  text.setFont(font);
  text.setString(_text);
  text.setCharacterSize(12);
  text.setColor(sf::Color::Black);
  text.setPosition(_y, _x);
  window->draw(text);
}

void    print_user(sf::RenderWindow *window, Infos const &infos)
{
  print_shape(window, 15, 180);
  print_title(window, "PC :", 25);
  print_text(window, infos._user.getMachineName(), 45);
  print_shape(window, 57, 1);
  print_title(window, "User :", 70);
  print_text(window, infos._user.getUserName(), 90);
  print_shape(window, 102, 1);
  print_title(window, "Date :", 115);
  print_text(window, infos._user.getDate(), 135);
  print_shape(window, 147, 1);
  print_title(window, "Heure :", 160);
  print_text(window, infos._user.getTime(), 180);
}

void    print_cpu(sf::RenderWindow *window, Infos const &infos)
{
  print_shape(window, 215, 225);
  print_title(window, "CPU :", 225);
  print_text(window, infos._core.getCPUModel(), 245);
  print_shape(window, 257, 1);
   std::ostringstream ss1;
  print_title(window, "CPU 1 :", 270);
  ss1 << infos._core.getCorePercent()[0] << " %";
  std::string a(ss1.str());
  print_text(window, a, 290);
  print_shape(window, 302, 1);
  std::ostringstream ss2;
  print_title(window, "CPU 2 :", 315);
  ss2 << infos._core.getCorePercent()[1] << " %";
  std::string b(ss2.str());
  print_text(window, b, 335);
  print_shape(window, 347, 1);
  std::ostringstream ss3;
  print_title(window, "CPU 3 :", 360);
  ss3 << infos._core.getCorePercent()[2] << " %";
  std::string c(ss3.str());
  print_text(window, c, 380);
  print_shape(window, 392, 1);
  std::ostringstream ss4;
  print_title(window, "CPU 4 :", 410);
  ss4 << infos._core.getCorePercent()[3] << " %";
  std::string d(ss4.str());
  print_text(window, d, 430);
}

void    print_kernel(sf::RenderWindow *window, Infos const &infos)
{
  print_shape(window, 470, 50);
  print_title(window, "RAM :", 480);
  std::ostringstream ss;
  ss << infos._core.getRam()[0] << "G  |  " << infos._core.getRam()[1] << "G";
  std::string s(ss.str());
  print_text(window, s, 500);

  print_shape(window, 550, 50);
  print_title(window, "OS :", 560);
  print_text(window, infos._user.getOpSys(), 580);

  print_shape(window, 630, 50);
  print_title(window, "Kernel :", 640);
  print_text(window, infos._user.getKernel(), 660);
}

void	print_data(sf::RenderWindow *window, Infos const &infos)
{
  print_shape(window, 710, 50);
  print_title(window, "Internet :", 720);
  std::ostringstream ss;
  ss << "Up : " <<infos._network.getUp() << "  |   Down : " << infos._network.getDown();
  std::string s(ss.str());
  print_text(window, s, 740);
}

void	print_graphCPU(sf::RenderWindow *window, Infos const &infos)
{
  float	val;
  int	place = 0;
  
  print_shape2(window, 215, 300, 39, 400, 0);
  val = (((infos._core.getCorePercent()[0]) + (infos._core.getCorePercent()[1]) +
	  (infos._core.getCorePercent()[2]) + (infos._core.getCorePercent()[3])) / 4);
  int size = int(val + 0.5);
  size *= 4;
  print_shape2(window, 216, 300 , 37 , size, size / 4);
}

void	print_graphCPU1(sf::RenderWindow *window, Infos const &infos)
{
  float	val;
  int	place = 0;
  
  print_shape2(window, 261, 300, 39, 400, 0);
  val = infos._core.getCorePercent()[0];
  int size = int(val + 0.5);
  size *= 4;
  print_shape2(window, 262, 300 , 37 , size, size / 4);
}

void	print_graphCPU2(sf::RenderWindow *window, Infos const &infos)
{
  float	val;
  int	place = 0;
  
  print_shape2(window, 306, 300, 39, 400, 0);
  val = infos._core.getCorePercent()[1];
  int size = int(val + 0.5);
  size *= 4;
  print_shape2(window, 307, 300 , 37 , size, size / 4);
}

void	print_graphCPU3(sf::RenderWindow *window, Infos const &infos)
{
  float	val;
  int	place = 0;
  
  print_shape2(window, 351, 300, 39, 400, 0);
  val = infos._core.getCorePercent()[2];
  int size = int(val + 0.5);
  size *= 4;
  print_shape2(window, 352, 300 , 37 , size, size / 4);
}

void	print_graphCPU4(sf::RenderWindow *window, Infos const &infos)
{
  float	val;
  int	place = 0;
  
  print_shape2(window, 396, 300, 39, 400, 0);
  val = infos._core.getCorePercent()[3];
  int size = int(val + 0.5);
  size *= 4;
  print_shape2(window, 397, 300 , 37 , size, size / 4);
}

void	print_asciiname(sf::RenderWindow *window)
{
  std::ifstream t("name.txt");
  std::string str((std::istreambuf_iterator<char>(t)),
		  std::istreambuf_iterator<char>());
  print_text2(window, str, 600, 600);
}
void    graphDisplay(Infos &infos)
{
  sf::RenderWindow window(sf::VideoMode(900, 800), "My GKrellm");

  while (window.isOpen())
    {
      updateInfos(infos);
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
      window.clear(sf::Color::Black);
      sf::Texture texture;
      texture.loadFromFile("gluke.jpg");
      sf::Sprite background(texture);
      window.draw(background);

      print_user(&window, infos);
      print_cpu(&window, infos);
      print_kernel(&window, infos);
      print_data(&window, infos);
      print_graphCPU(&window, infos);
      print_graphCPU1(&window, infos);
      print_graphCPU2(&window, infos);
      print_graphCPU3(&window, infos);
      print_graphCPU4(&window, infos);
      print_asciiname(&window);
      
      window.display();
    }
}
