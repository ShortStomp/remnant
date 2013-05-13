#include "../engine.hpp"
#include "../messages/message.hpp"
#include "../entity/entity.hpp"
#include "../component/gravity_component.hpp"
#include "gravity_system.hpp"

//===----------------------------------------------------------------------===//
//
// Applies a constant gravitational force to each gravitational component.
//
//===----------------------------------------------------------------------===//
void
ec::gravity_system::apply_gravitational_forces(ec::engine &engine)
{
  for(const auto entity_ptr : engine.Entities) {

    if(entity_ptr == nullptr) { // can't send the entity a message
      continue;
    }

    message move_message(MESSAGE_TYPE_ACCELERATION);
    move_message.Accelerate_Message.Y_Acceleration = gravity_system::GRAVITATIONAL_CONSTANT;

    entity_ptr->Message_Queue.push(move_message);
  }

}