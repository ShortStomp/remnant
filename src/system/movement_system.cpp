#include <SFML\System\Vector2.hpp>
#include "movement_system.hpp"
#include "../messages/move_message.hpp"
#include "../component/transform_component.hpp"
#include "../component/movement_component.hpp"

//===----------------------------------------------------------------------===//
//
// Update the transform component's position.
//
//===----------------------------------------------------------------------===//
void
rem::movement_system::move_entity(const movement_component &movement, transform_component &transform)
{
  transform.move(movement.Velocity);
}