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
// The parent_component provides a connection between two different entities in a
// pseudo parent/child relationship.
//
//===----------------------------------------------------------------------===//
#ifndef _PARENT_COMPONENT_HPP_
#define _PARENT_COMPONENT_HPP_
#include <SFML\System\Vector2.hpp>
#include "icomponent.hpp"

namespace ec
{
  // forward declarations
  class entity;

  struct parent_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_PARENT;

    // members
    entity        *parent_entity_ptr;
    sf::Vector2f  Offset;

    // constructors
    parent_component(void) : icomponent(COMPONENT_TYPE), parent_entity_ptr(nullptr) { }
  };
}
#endif // _PARENT_COMPONENT_HPP_