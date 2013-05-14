#include "..\engine.hpp"
#include "..\component\sprite_component.hpp"
#include "..\entity\entity.hpp"
#include "graphics_system.hpp"

//===----------------------------------------------------------------------===//
//
// The function update_screen() is responsible for drawing the screen within the
// window.
//
//===----------------------------------------------------------------------===//
void
ec::graphics_system::update_screen(ec::engine &engine)
{
  // clear the window with black color
  engine.Window.clear();

  // draw everything here
  for(const auto entity_ptr : engine.Entities) {
    const auto sprite_component_ptr = entity_helpers::get_sprite_component(entity_ptr);       // alias
    const auto transform_component_ptr = entity_helpers::get_transform_component(entity_ptr); // alias

    if(sprite_component_ptr == nullptr) { // nothing to draw
      continue;
    }

    if(transform_component_ptr == nullptr) {
      __debugbreak();
    }

    const auto parent_component_ptr = entity_helpers::get_parent_component(entity_ptr); // alias
    const auto parent_entity_ptr = parent_component_ptr->parent_entity_ptr;

    if(parent_entity_ptr == entity_ptr) {
      __debugbreak();
    }
    const auto parent_transform_ptr = entity_helpers::get_transform_component(parent_entity_ptr);

    //sprite_component_ptr->Sprite.setPosition(transform_component_ptr->getPosition());
    //sprite_component_ptr->Sprite.setRotation(transform_component_ptr->getRotation());
    //sprite_component_ptr->Sprite.setScale(transform_component_ptr->getScale());

    if(parent_component_ptr != nullptr && parent_entity_ptr != nullptr && parent_transform_ptr != nullptr) {
      //auto new_transform = transform_component_ptr->getTransform().combine(parent_transform_ptr->getTransform());
      
      const auto parent_transform_pos = parent_transform_ptr->getPosition();
      const auto this_transform = transform_component_ptr->getPosition();

      const auto combined_transform = parent_transform_ptr->getTransform() * transform_component_ptr->getTransform();
      
      engine.Window.draw(sprite_component_ptr->Sprite, combined_transform);
      continue;
    }

    if(parent_component_ptr != nullptr) {
      sprite_component_ptr->Sprite.move(parent_component_ptr->Offset);
    }
    engine.Window.draw(sprite_component_ptr->Sprite);
  }

  // current frame ends here
  engine.Window.display();
}