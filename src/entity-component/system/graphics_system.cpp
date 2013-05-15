#include "..\engine.hpp"
#include "..\component\sprite_component.hpp"
#include "..\entity\entity.hpp"
#include "graphics_system.hpp"

//===----------------------------------------------------------------------===//
//
// TODO: comment
//
//===----------------------------------------------------------------------===//
void
draw_scenegraphs(
  sf::RenderWindow &window,
  const ec::transform_component &transform_component,
  const ec::sprite_component    &sprite_component,
  const ec::parent_component    &parent_component
  )
{
  using namespace ec;

  const auto parent_entity_ptr = parent_component.parent_entity_ptr; // alias

  if(parent_entity_ptr == parent_component.Entity_Pointer) {
    __debugbreak();
  }
  
  const auto parent_transform_ptr = entity_helpers::get_transform_component(parent_entity_ptr);
  if(parent_transform_ptr == nullptr) {
    __debugbreak();
  }


  // combine the parent transform with the transform component 
  const auto combined_transform = parent_transform_ptr->getTransform() * transform_component.getTransform();
    
  window.draw(sprite_component.Sprite, combined_transform);
}

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

    if(parent_component_ptr != nullptr) { // drawing a scenegraph
      draw_scenegraphs(engine.Window, *transform_component_ptr, *sprite_component_ptr, *parent_component_ptr);
      continue;
    }

    sprite_component_ptr->Sprite.setPosition(transform_component_ptr->getPosition());
    sprite_component_ptr->Sprite.setRotation(transform_component_ptr->getRotation());
    sprite_component_ptr->Sprite.setScale(transform_component_ptr->getScale());

    engine.Window.draw(sprite_component_ptr->Sprite);
  }

  // current frame ends here
  engine.Window.display();
}