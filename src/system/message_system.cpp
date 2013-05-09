#include <cstdio>
#include <iostream>
#include "../engine.hpp"
#include "../entity/entity.hpp"
#include "../messages/message.hpp"
#include "../messages/move_message.hpp"

#include "../system/input_system.hpp"
#include "../system/movement_system.hpp"

#include "../entity/entity_helpers.hpp"
#include "../component/movement_component.hpp"

#include "message_system.hpp"

//===----------------------------------------------------------------------===//
//
// Process a single message for an entity.
//
//===----------------------------------------------------------------------===//
void process_message(const rem::message message, rem::entity *const entity_ptr)
{
  using namespace rem;

  if(message.Type == MESSAGE_TYPE_MOVE) {
    const auto move_ptr = entity_helpers::get_movement_component(entity_ptr);
    if(move_ptr != nullptr) {
      //movement_system::move_entity(*move_ptr, entity_ptr->Transform);
    }
  }
  else if(message.Type == MESSAGE_TYPE_ACCELERATION) {
    const auto move_ptr = entity_helpers::get_movement_component(entity_ptr);
    if(move_ptr != nullptr) {
      move_ptr->Acceleration.x += message.Accelerate_Message.X_Acceleration;
      move_ptr->Acceleration.y += message.Accelerate_Message.Y_Acceleration;
    }
  }
  else if(message.Type == MESSAGE_TYPE_ROTATION) {
    entity_ptr->Transform.rotate(message.Rotation_Message.Angle);
  }

}


//===----------------------------------------------------------------------===//
//
// Process the message queue for a single entity.
//
//===----------------------------------------------------------------------===//
void process_entity(rem::entity *const entity_ptr)
{
  using namespace rem;

  auto &queue = entity_ptr->Message_Queue; // alias for the message queue on the entity

  while(queue.empty() == false) {
    
    // process the message at the top of the queue.
    process_message(queue.front(), entity_ptr);

    // remove the message from the top of the queue.
   queue.pop(); 
  }
}


//===----------------------------------------------------------------------===//
//
// Iterate ove the all the entities in the engine, and process each one's
// message queue.
//
//===----------------------------------------------------------------------===//
void rem::message_system::process_messages(rem::engine &engine)
{
  for(const auto it : engine.Entities) {
    process_entity(it);
  }
}