#include "..\engine.hpp"
#include "..\entity\entity.hpp"
//#include <boost\log\trivial.hpp>
#include "graphics_system.hpp"
#include "../sprite_group.hpp"

//===----------------------------------------------------------------------===//
//
// If the entity_ptr has a parent_component
//
//===----------------------------------------------------------------------===//
sf::Transform
scenegraph_transform(const ec::transform_component &transform, ec::entity *const parent_ptr)
{
  using namespace ec;
  sf::Transform result = transform.getTransform();

  if(parent_ptr == nullptr) { // entity is not a member of a scenegraph
    return result;
  }

  const auto parent_transform_component = entity_helpers::get_transform_component(parent_ptr);
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
  for(const auto &block : engine.TetrisBlocks) {
    engine.Window.draw(block);
  }

  for(const auto &mblock : engine.MovableTetrisBlocks) {
    engine.Window.draw(mblock);
  }

  /*  for(const auto entity_ptr : engine.Sprites) {

    if(entity_ptr == nullptr) { // error
      //BOOST_TRIVIAL_LOG(error) << "Error nullptr entity* in engine.Entities collection." << std::endl;
      __debugbreak();
    }

    // if entity_ptr is a member of a scenegraph, then multiply our transform with the parent's transform.
    //const sf::Transform transform = scenegraph_transform(*transform_component_ptr, entity_ptr->Parent);

    //sprite_component_ptr->Sprite.setPosition(transform_component_ptr->getPosition());
    //sprite_component_ptr->Sprite.setRotation(transform_component_ptr->getRotation());
    //sprite_component_ptr->Sprite.setScale(transform_component_ptr->getScale());

    //engine.Window.draw(*entity_ptr);
    //engine.Window.draw(sprite_component_ptr->Sprite, transform);
  }

  */

  // current frame ends here
  engine.Window.display();
}