//
// author: Benjamin Adamson and Wesley Kos
// TODO
#include <SFML\Window\Event.hpp>
#include "engine.hpp"
#include "system\input_system.hpp"
#include "system\graphics_system.hpp"
#include "game.hpp"


void
rem::game::game_loop(
  rem::engine &engine
  )
{
  bool finished = false;

  while(finished == false) {
    
    rem::system::input_system::process_input(engine, finished);

    rem::system::graphics_system::update_screen(engine);
  }
}