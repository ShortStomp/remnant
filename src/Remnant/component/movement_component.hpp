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
//
//===----------------------------------------------------------------------===//
#ifndef _MOVEMENT_COMPONENT_HPP_
#define _MOVEMENT_COMPONENT_HPP_
#include <SFML\System\Vector2.hpp>
#include "icomponent.hpp"
namespace rem
{
  struct movement_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_MOVEMENT;

    // members
    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;

    // constructors
    movement_component(void) : icomponent(COMPONENT_TYPE) { }
  };
}
#endif