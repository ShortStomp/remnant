//
// author: Benjamin Adamson and Wesley Kos
// TODO:
#include <SFML\Window\Event.hpp>
#include "..\engine.hpp"
#include "input_system.hpp"

void
rem::system::input_system::process_input(rem::engine &engine, bool &game_finished)
{
  sf::Event event_buffer;
  while(engine.Window.pollEvent(event_buffer)) {
    
    if(event_buffer.type == sf::Event::Closed) {
      game_finished = true;
    }
  }

}