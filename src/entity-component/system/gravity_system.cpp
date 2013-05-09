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
  using namespace ec;

  for(const auto it : engine.Gravity_Components) {

    if(it->Entity_Pointer == nullptr) { // can't send the entity a message
      continue;
    }

    message move_message(MESSAGE_TYPE_ACCELERATION);
    move_message.Accelerate_Message.Y_Acceleration = gravity_system::GRAVITATIONAL_CONSTANT;

    auto &entity = *it->Entity_Pointer; // alias
    entity.Message_Queue.push(move_message);
  }

}