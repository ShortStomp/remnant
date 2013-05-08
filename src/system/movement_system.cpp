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
  entity.Transform.move(move_message.X_Distance, move_message.Y_Distance);
}