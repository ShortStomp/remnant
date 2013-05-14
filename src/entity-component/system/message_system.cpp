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
void process_message(const ec::message message, ec::entity *const entity_ptr)
{
  using namespace ec;

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
    const auto transform_ptr = entity_helpers::get_transform_component(entity_ptr);
    if(transform_ptr == nullptr) { // no transform component to update
      return;
    }
    transform_ptr->rotate(message.Rotation_Message.Angle);
  }

}


//===----------------------------------------------------------------------===//
//
// Process the message queue for a single entity.
//
//===----------------------------------------------------------------------===//
void process_entity(ec::entity *const entity_ptr)
{
  using namespace ec;

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
void ec::message_system::process_messages(ec::engine &engine)
{
  for(const auto it : engine.Entities) {
    process_entity(it);
  }
}