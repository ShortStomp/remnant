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
// The transform component is the aggregate of an entity's Rotation, Position,
// and Scale.
//
//===----------------------------------------------------------------------===//
#ifndef _TRANSFORM_COMPONENT_HPP_
#define _TRANSFORM_COMPONENT_HPP_
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include "icomponent.hpp"

namespace ec
{
  struct transform_component :
    public sf::Transformable,
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_TRANSFORM;

    // constructors
    transform_component(void) : icomponent(COMPONENT_TYPE) { }
  };
}
#endif // _TRANSFORM_COMPONENT_HPP_