#include "../engine.hpp"
#include "../entity/entity.hpp"
#include "collision_system.hpp"


//===----------------------------------------------------------------------===//
//
// Update the transform component based on an elapsed time and a movement
// component.
//
//===----------------------------------------------------------------------===//
bool 
ec::collision_system::collision_detection(ec::engine &engine, ec::entity *const moving_entity_ptr)
{  
  
  
  
  for(const auto entity_ptr : engine.Entities) {
    const auto stationary_entity = ec::entity_helpers::get_sprite_component(entity_ptr);

    
    // Don't do anything if entities are the same
   /* if(moving_entity != stationary_entity) {
      const auto moving_bounds = moving_entity->Sprite.getGlobalBounds();

      if(moving_bounds.intersects(stationary_entity->Sprite.getGlobalBounds())) {
        return true;
      }
    }*/

  }
  return false;
}
