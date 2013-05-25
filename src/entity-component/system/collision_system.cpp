#include <boost\log\trivial.hpp>
#include "../engine.hpp"
#include "../entity/entity.hpp"
#include "collision_system.hpp"
#include "movement_system.hpp"

//===----------------------------------------------------------------------===//
//
// This function will update every bounding box which the engine knows about.
// It will multiple child and parent transform_components and store the 
// corresponding FloatRect in the collision_components bounding_box.
//
//===----------------------------------------------------------------------===//
void
ec::collision_system::update_bounding_boxes(ec::engine &engine)
{
  using namespace collision_system;

  for(const auto entity_ptr : engine.Entities) {

    if(entity_ptr == nullptr) { // error
      continue;
    }
    const auto transform_ptr = entity_helpers::get_transform_component(entity_ptr); // alias
    if(transform_ptr == nullptr) { // no transform component on this entity
      continue;
    } 
    
    const auto collision_ptr = entity_helpers::get_collision_component(entity_ptr);
    if(collision_ptr == nullptr) { // no transform component on this entity
      continue;
    } 
    
    collision_ptr->x_collision = false;
    collision_ptr->y_collision = false;

    const auto sprite_ptr = entity_helpers::get_sprite_component(entity_ptr);
    if(sprite_ptr == nullptr) { // no transform component on this entity
      continue;
    } 
    
    const auto parent_transform_ptr = entity_helpers::get_transform_component(entity_ptr->Parent);

    auto result = parent_transform_ptr->getTransform() * transform_ptr->getTransform();
    collision_ptr->bounding_box = result.transformRect(sprite_ptr->Sprite.getGlobalBounds());

  }
}

//===----------------------------------------------------------------------===//
//
// This function will check for a collision. It will check each child a parent
// has against every entity in the engine.
// TODO: Add a parent check so it checks for a broader collision and if there
// is check the children for collision.
//
//===----------------------------------------------------------------------===//
void
  ec::collision_system::is_colliding(ec::entity &moving_entity, ec::movement_component &movement_moving_parent_ptr, ec::collision_component &moving_collision_ptr, ec::engine &engine)
{

  // Iterate through all of the children checking for actual collisions
  for(const auto moving_children_ptr : moving_entity.Child_List) {
    const auto transform_moving_ptr = ec::entity_helpers::get_transform_component(moving_children_ptr);
    const auto collision_moving_ptr = ec::entity_helpers::get_collision_component(moving_children_ptr);
    const auto movement_moving_ptr = ec::entity_helpers::get_movement_component(moving_children_ptr);

    // Set up FloatRects which we can check for interesction in the future.
    sf::FloatRect y_movement_bounding_box = collision_moving_ptr->bounding_box;
    sf::FloatRect x_movement_bounding_box = collision_moving_ptr->bounding_box;

    // Update FloatRects with velocity.
    y_movement_bounding_box.top = collision_moving_ptr->bounding_box.top + movement_moving_parent_ptr.Velocity.y + (movement_moving_parent_ptr.Acceleration.y * engine.Elapsed_Time);
    x_movement_bounding_box.left = collision_moving_ptr->bounding_box.left + movement_moving_parent_ptr.Velocity.x + (movement_moving_parent_ptr.Acceleration.x * engine.Elapsed_Time);

    // Check the current child against each of the pieces that it can run into.
    for(const auto entity_ptr : engine.Entities) {

      // We don't want to compare child to parent.
      if(entity_ptr->Parent == nullptr) {
        continue;
      }

      // We don't want to compare children because it would always be true.
      if(entity_ptr->Parent == &moving_entity) {
        continue;
      }
      
      if(entity_ptr == nullptr) { // error
        continue;
      }

      const auto collision_stationary_ptr = ec::entity_helpers::get_collision_component(entity_ptr);
      if(collision_stationary_ptr == nullptr) { // no transform component on this entity
        continue;
      }
      
      if(y_movement_bounding_box.intersects(collision_stationary_ptr->bounding_box)) {
        // Let the child and parent know that a collision has happened in the Y direction
        collision_moving_ptr->y_collision = true;        
          moving_collision_ptr.y_collision = true;      
      }
      if(x_movement_bounding_box.intersects(collision_stationary_ptr->bounding_box)) {
        // Let the child and parent know that a collision has happened in the X direction
        collision_moving_ptr->x_collision = true;
        moving_collision_ptr.x_collision = true;
      }
    }
  }
}


