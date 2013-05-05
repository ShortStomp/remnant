//
// author: Benjamin Adamson and Wesley Kos
// TODO:
#include "engine.hpp"
#include <string>

rem::engine::engine(void)
{
  const std::string window_title("Remnant Title Text");
  const sf::VideoMode window_mode(1024, 768);
  const auto window_style = sf::Style::Titlebar | sf::Style::Close |sf::Style::Resize;
 
  Window.create(window_mode, window_title, window_style);
}