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
    const auto sprite_component_ptr = entity_helpers::get_sprite_component(entity_ptr);
    const auto transform_component_ptr = entity_helpers::get_transform_component(entity_ptr); // alias

    if(sprite_component_ptr == nullptr || transform_component_ptr == nullptr) {
      __debugbreak();
    }

    sprite_component_ptr->Sprite.setPosition(transform_component_ptr->getPosition());
    sprite_component_ptr->Sprite.setRotation(transform_component_ptr->getRotation());
    sprite_component_ptr->Sprite.setScale(transform_component_ptr->getScale());
    engine.Window.draw(sprite_component_ptr->Sprite);
  }

  // current frame ends here
  engine.Window.display();
}