#include <SFML\Window\Event.hpp>
#include "..\engine.hpp"
#include "input_system.hpp"
#include "..\component\input_component.hpp"
#include "..\messages\message.hpp"
#include "..\entity\entity.hpp"

//===----------------------------------------------------------------------===//
//
// The function process_input() is responsible for processing all events and routing
// all input events to their correct targets (components).
//
//===----------------------------------------------------------------------===//
void
rem::system::input_system::process_input(rem::engine &engine, bool &game_finished)
{
  sf::Event event_buffer;
  while(engine.Window.pollEvent(event_buffer)) {
    for(const auto it : engine.Input_Component) {
      message keypress_message(KEYPRESS_MESSAGE_TYPE);
      keypress_message.Keypress_Message.Key = sf::Keyboard::W;

      /*keypress_message keypress(sf::Keyboard::W);*/
      it->Parent_ptr->Message_Queue.push(keypress_message);
    }
    if(event_buffer.type == sf::Event::Closed) {
      game_finished = true;
    }
  }

}