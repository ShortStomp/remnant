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

namespace rem
{
  struct transform_component :
    public sf::Transformable
  {
    // members
    sf::Transformable transform;
  };
}
#endif // _TRANSFORM_COMPONENT_HPP_