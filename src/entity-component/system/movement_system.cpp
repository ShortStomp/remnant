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
  for(const auto entity_ptr : engine.Entities) {

    if(entity_ptr == nullptr) { // error
      continue;
    }

    const auto movement_ptr = entity_helpers::get_movement_component(entity_ptr);  // alias
    if(movement_ptr == nullptr) { // no movement component on this entity
      continue;
    }

    const auto transform_ptr = entity_helpers::get_transform_component(entity_ptr); // alias
    if(transform_ptr == nullptr) { // no transform component on this entity
      continue;
    }
    
    upate_transform_from_movement(engine.Elapsed_Time, *transform_ptr, *movement_ptr);
  }
}