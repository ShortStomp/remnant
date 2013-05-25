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
#ifndef _COLLISION_COMPONENT_HPP_
#define _COLLISION_COMPONENT_HPP_
#include <SFML\System\Vector2.hpp>
#include "icomponent.hpp"

namespace ec
{
  struct collision_component:
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_COLLISION;

    // members
    sf::FloatRect bounding_box;
    bool y_collision;
    bool x_collision;

    // constructors
    collision_component(void) : icomponent(COMPONENT_TYPE) { }
  };
}
#endif