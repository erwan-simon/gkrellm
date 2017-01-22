//
// graphDisplay2.cpp for  in /home/antoine/rendu/Piscine_cpp/cpp_gkrellm
// 
// Made by antoine
// Login   <antoine.roche@epitech.eu>
// 
// Started on  Sun Jan 22 09:29:26 2017 antoine
// Last update Sun Jan 22 09:34:29 2017 antoine
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
  text.setCharacterSize(25);
  text.setColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
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
  text.setCharacterSize(65);
  text.setColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text.setPosition(_y, _x);
  window->draw(text);
}
