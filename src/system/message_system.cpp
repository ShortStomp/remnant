#include "message_system.hpp"
#include "../engine.hpp"
#include "../entity/entity.hpp"
#include "../messages/message.hpp"
#include "../messages/move_message.hpp"

#include "../system/input_system.hpp"
#include "../system/movement_system.hpp"


//===----------------------------------------------------------------------===//
//
// Process a single message for an entity.
//
//===----------------------------------------------------------------------===//
void process_message(const rem::message message, rem::entity *const entity_ptr)
{
  using namespace rem;

  if(message.Type == MESSAGE_TYPE_KEYPRESS) {
    rem::input_system::process_keypress_message(message.Keypress_Message, entity_ptr);
  }
  else if(message.Type == MESSAGE_TYPE_MOVE) {
    movement_system::move_entity(*entity_ptr, message.Move_Message);
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