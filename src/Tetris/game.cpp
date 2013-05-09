#include <SFML\Window\Event.hpp>
#include "..\entity-component\\engine.hpp"
#include "..\entity-component\system\message_system.hpp"
#include "..\entity-component\system\input_system.hpp"
#include "..\entity-component\system\movement_system.hpp"
#include "..\entity-component\system\graphics_system.hpp"
#include "..\entity-component\system\gravity_system.hpp"
#include "game.hpp"


//===----------------------------------------------------------------------===//
//
// The main game loop. When this function exits the game is over. The game loop
// iterates over the different systems in order, processing input, updating ai,
// drawing the screen, playing audio, etc...
//
//===----------------------------------------------------------------------===///
void
tet::game::game_loop(
  ec::engine &engine
  )
{
  using namespace ec;

  sf::Clock clock_instance;
  bool finished = false;

  while(finished == false) {

    // update the elapsed time
    engine.Elapsed_Time = clock_instance.restart().asSeconds();

    message_system::process_messages(engine);
    
    input_system::process_input(engine, finished);

    gravity_system::apply_gravitational_forces(engine);

    movement_system::move_entities(engine);

    graphics_system::update_screen(engine);
  }
}