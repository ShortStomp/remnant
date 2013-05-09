#include <algorithm>
#include <SFML\Window\Event.hpp>
#include "..\engine.hpp"
#include "input_system.hpp"
#include "..\component\input_component.hpp"
#include "..\messages\acceleration_message.hpp"
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

  const auto entity_ptr = input_component_ptr->Parent_ptr;
  const auto move_component_ptr = entity_helpers::get_movement_component(entity_ptr);

  const auto acceleration = sf::Vector2f(1.03f, 2.03f);//(move_component_ptr != nullptr) ? move_component_ptr->Acceleration : sf::Vector2f(0.0f, 0.0f);

  message accelerate_message(MESSAGE_TYPE_ACCELERATION);

  bool send_message(false);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    accelerate_message.Accelerate_Message.Y_Acceleration = -acceleration.y;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    accelerate_message.Accelerate_Message.X_Acceleration = -acceleration.x;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    accelerate_message.Accelerate_Message.Y_Acceleration = acceleration.y;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
   accelerate_message.Accelerate_Message.X_Acceleration = acceleration.x;
   send_message = true;
  }

  if(send_message == true) {
    input_component_ptr->Parent_ptr->Message_Queue.push(accelerate_message);
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

    std::for_each(engine.Input_Component.begin(), engine.Input_Component.end(), on_key_press);

    if(event_buffer.type == sf::Event::Closed) {
      game_finished = true;
    }
  }

}