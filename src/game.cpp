#include <SFML\Window\Event.hpp>
#include "engine.hpp"
#include "system\input_system.hpp"
#include "system\graphics_system.hpp"
#include "system\message_system.hpp"
#include "game.hpp"


//===----------------------------------------------------------------------===//
//
// The main game loop. When this function exits the game is over. The game loop
// iterates over the different systems in order, processing input, updating ai,
// drawing the screen, playing audio, etc...
//
//===----------------------------------------------------------------------===///
void
rem::game::game_loop(
  rem::engine &engine
  )
{
  bool finished = false;
  
  while(finished == false) {

    rem::message_system::process_messages(engine);
    
    rem::input_system::process_input(engine, finished);

    rem::graphics_system::update_screen(engine);
  }
}