//===-----------------------------------------------------------------------===//
//
//                     The Remnant Source code
//
// Authors:
//
//    Benjamin Adamson (adamson.benjamin@gmail.com)
//    Wesley Kos (kos.wesley@gmail.com)
//
//===----------------------------------------------------------------------===//
//
// The graphics system is the system responsible for determining if the entity
// is colliding with anything.
//
//===----------------------------------------------------------------------===///
#ifndef _COLLISION_SYSTEM_HPP_
#define _COLLISION_SYSTEM_HPP_
#include <SFML\System\Vector2.hpp>
#include "..\component\collision_component.hpp"
namespace ec
{
namespace collision_system
{
  void update_bounding_boxes(ec::engine &engine);
  void is_colliding(ec::entity &moving_entity, ec::movement_component &movement_moving_parent_ptr, ec::collision_component &moving_collision_ptr, ec::engine &engine);
  bool is_colliding(const sf::FloatRect &a, const sf::FloatRect &b);
}
}
#endif