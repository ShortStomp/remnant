#include "..\engine.hpp"
#include "..\component\sprite_component.hpp"
#include "..\entity\entity.hpp"
//#include <boost\log\trivial.hpp>
#include "graphics_system.hpp"


//===----------------------------------------------------------------------===//
//
// If the entity_ptr has a parent_component
//
//===----------------------------------------------------------------------===//
sf::Transform
check_scenegraph_transform(const ec::transform_component &transform, ec::entity *const entity_ptr)
{
  using namespace ec;
  sf::Transform result = transform.getTransform();
  const auto parent_component_ptr = entity_helpers::get_parent_component(entity_ptr); // alias

  if(parent_component_ptr == nullptr) { // entity is not a member of a scenegraph
    return result;
  }

  const auto parent_transform_component = entity_helpers::get_transform_component(parent_component_ptr->parent_entity_ptr);
  if(parent_transform_component == nullptr) { // parent component is not a member of a scenegraph
    //BOOST_LOG_TRIVIAL(warning) << "TODO: figure out if this should be a bug, or not." << std::endl;
    return result;
  }

  // combine the parent transform with the transform component
  result = parent_transform_component->getTransform() * transform.getTransform();
  return result;
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
      //BOOST_LOG_TRIVIAL(error) << "Entity with sprite component, missing transform component." << std::endl;
      __debugbreak();
    }

    // if entity_ptr is a member of a scenegraph, then multiply our transform with the parent's transform.
    const sf::Transform transform = check_scenegraph_transform(*transform_component_ptr, entity_ptr);

    //sprite_component_ptr->Sprite.setPosition(transform_component_ptr->getPosition());
    //sprite_component_ptr->Sprite.setRotation(transform_component_ptr->getRotation());
    //sprite_component_ptr->Sprite.setScale(transform_component_ptr->getScale());

    engine.Window.draw(sprite_component_ptr->Sprite, transform);
  }

  // current frame ends here
  engine.Window.display();
}