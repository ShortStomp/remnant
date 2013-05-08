#include "movement_system.hpp"
#include "../entity/entity.hpp"
#include "../messages/move_message.hpp"

//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//
void
rem::movement_system::move_entity(rem::entity &entity, const rem::move_message move_message)
{
  entity.Transform.Position.x += move_message.X_Distance;
  entity.Transform.Position.y += move_message.Y_Distance;
}