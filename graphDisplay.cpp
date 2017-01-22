//
// graphDisplay.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sun Jan 22 02:30:51 2017 antoine
// Last update Sun Jan 22 02:59:17 2017 antoine
//

#include <iostream>
#include <string>

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
  // text.setPosition(12, _x);
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
  // text.setPosition(12, _x);
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width/2.0f,
		 textRect.top  + textRect.height/2.0f);
  text.setPosition(sf::Vector2f(300/2.0f, _x));
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
  print_title(window, "CPU 1 :", 270);
  print_text(window, "20%", 290);
  print_shape(window, 302, 1);
  print_title(window, "CPU 2 :", 315);
  print_text(window, "20%", 335);
  print_shape(window, 347, 1);
  print_title(window, "CPU 3 :", 360);
  print_text(window, "20%", 380);
  print_shape(window, 392, 1);
  print_title(window, "CPU 4 :", 410);
  print_text(window, "20%", 430);
}

void    print_kernel(sf::RenderWindow *window, Infos const &infos)
{
  std::string _std = "coucouctwaawawa";

  print_shape(window, 470, 50);
  print_title(window, "RAM :", 480);
  print_text(window, "xadaza", 500);

  print_shape(window, 550, 50);
  print_title(window, "OS :", 560);
  print_text(window, "wawawlalalalallala", 580);

  print_shape(window, 630, 50);
  print_title(window, "Kernel :", 640);
  print_text(window, "azesrdtfgyuhjfghwawawlalalalallala", 660);

}


void    graphDisplay(Infos &infos)
{
  sf::RenderWindow window(sf::VideoMode(300, 700), "My GKrellm");

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

      window.display();
    }
}
