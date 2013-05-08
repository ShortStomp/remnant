#include <algorithm>
#include <SFML\Window\Event.hpp>
#include "..\engine.hpp"
#include "input_system.hpp"
#include "..\component\input_component.hpp"
#include "..\messages\message.hpp"
#include "..\entity\entity.hpp"

//===----------------------------------------------------------------------===//
//
// TODO: comment this.
//
//===----------------------------------------------------------------------===//
void
on_key_press(rem::input_component *const input_component_ptr)
{
  using namespace rem;

  // TODO: movement speed should be retrieved from the entity, not hard-coded.
  const auto movement_speed = 5;
  message move_message(MESSAGE_TYPE_MOVE);

  bool send_message(false);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    move_message.Move_Message.Y_Distance = -movement_speed;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    move_message.Move_Message.X_Distance = -movement_speed;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    move_message.Move_Message.Y_Distance = movement_speed;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
   move_message.Move_Message.X_Distance = movement_speed;
   send_message = true;
  }

  if(send_message == true) {
    input_component_ptr->Parent_ptr->Message_Queue.push(move_message);
  }
}

//===----------------------------------------------------------------------===//
//
// The function process_input() is responsible for processing all events and routing
// all input events to their correct targets (components).
//
//===----------------------------------------------------------------------===//
void
rem::input_system::process_input(rem::engine &engine, bool &game_finished)
{
  sf::Event event_buffer;
  while(engine.Window.pollEvent(event_buffer)) {

    if(event_buffer.type == sf::Event::KeyPressed) {
      std::for_each(engine.Input_Component.begin(), engine.Input_Component.end(), on_key_press);
    }

    if(event_buffer.type == sf::Event::Closed) {
      game_finished = true;
    }
  }

}