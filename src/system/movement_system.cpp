#include "movement_system.hpp"
#include "../messages/move_message.hpp"

//===----------------------------------------------------------------------===//
//
// Update the transform component's position.
//
//===----------------------------------------------------------------------===//
void
rem::movement_system::move_entity(rem::transform_component &transform, const rem::move_message move_message)
{
  transform.move(move_message.X_Distance, move_message.Y_Distance);
}