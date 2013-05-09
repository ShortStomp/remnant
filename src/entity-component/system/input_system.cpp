#include <algorithm>
#include <SFML\Window\Event.hpp>
#include "..\engine.hpp"
#include "input_system.hpp"
#include "..\component\input_component.hpp"
#include "..\messages\acceleration_message.hpp"
#include "..\entity\entity.hpp"

//===----------------------------------------------------------------------===//
//
// TODO: comment
// 
//===----------------------------------------------------------------------===//
void
process_rotation_keys(rem::entity &entity)
{
  using namespace rem;

  const auto rotation_angle = 5.0f;

  message rotation_message(MESSAGE_TYPE_ROTATION);

  bool send_message(false);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
    rotation_message.Rotation_Message.Angle = rotation_angle;
    send_message = true;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
    rotation_message.Rotation_Message.Angle = -rotation_angle;
    send_message = true;
  }

  if(send_message == true) {
    entity.Message_Queue.push(rotation_message);
  }
}


//===----------------------------------------------------------------------===//
//
// Check for keys that effect player movement, current the WASD keys.
//
//===----------------------------------------------------------------------===//
void
process_movement_keys(rem::entity &entity)
{
  using namespace rem;

  const auto acceleration = sf::Vector2f(1.03f, 2.03f);

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
    entity.Message_Queue.push(accelerate_message);
  }
}


//===----------------------------------------------------------------------===//
//
// TODO: comment this.
//
//===----------------------------------------------------------------------===//
void
on_key_press(rem::input_component *const input_component_ptr)
{
  if(input_component_ptr == nullptr) { // error
    return;
  }

  if(input_component_ptr->Entity_Pointer == nullptr) {
    // detached component, no entity to send message too
    return;
  }

  auto &entity = *input_component_ptr->Entity_Pointer; // alias

  process_movement_keys(entity);
  process_rotation_keys(entity);
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