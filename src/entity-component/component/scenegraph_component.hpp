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
// TODO: comment
//
//===----------------------------------------------------------------------===//
#ifndef _SCENEGRAPH_COMPONENT_HPP_
#define _SCENEGRAPH_COMPONENT_HPP_
#include <SFML\System\Vector2.hpp>
#include "icomponent.hpp"

namespace ec
{
  // forward declarations
  class entity;

  struct scenegraph_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_SCENEGRAPH;

    // members
    scenegraph_component        *root_scenegraph_ptr;
    sf::Vector2f  Offset;

    // constructors
    scenegraph_component(void) : icomponent(COMPONENT_TYPE), root_scenegraph_ptr(nullptr) { }
  };
}
#endif // _SCENEGRAPH_COMPONENT_HPP_