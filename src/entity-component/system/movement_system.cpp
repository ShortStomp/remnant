#include <iostream>
#include <SFML\System\Vector2.hpp>
#include "../engine.hpp"
#include "../messages/move_message.hpp"
#include "../component/transform_component.hpp"
#include "../component/movement_component.hpp"
#include "../entity/entity.hpp"
#include "movement_system.hpp"

//===----------------------------------------------------------------------===//
//
// Update the transform component based on an elapsed time and a movement
// component.
//
//===----------------------------------------------------------------------===//
void
upate_transform_from_movement(const float elapsed_time, ec::transform_component &transform, ec::movement_component &movement)
{
  // calculate the vleocity from the standard
  // v = a*t + v0
  // physics equation.
  const auto velocity = (movement.Acceleration * elapsed_time) + movement.Velocity;

  transform.move(velocity);
}


//===----------------------------------------------------------------------===//
//
// Iterate over each movement_component in the engine and update their corresponding
// transform component.
//
//===----------------------------------------------------------------------===//
void
ec::movement_system::move_entities(engine &engine)
{
  for(const auto it : engine.Movement_Components) {

    if(it->Entity_Pointer == nullptr) { // error
      continue;
    }

    auto &entity = *it->Entity_Pointer; // alias
    auto &movement = *it;               // alias
    upate_transform_from_movement(engine.Elapsed_Time, entity.Transform, movement);
  }
}