//===-----------------------------------------------------------------------===//
//
//                     The Remnant Source code
//
// Authors:
//
//    Benjamin Adamson (adamson.benjamin@gmail.com)
//    Wesley Kos (kos.wesley@gmail.com)
//
#ifndef _COMPONENT_REGISTRY_HPP_
#define _COMPONENT_REGISTRY_HPP_

namespace ec
{
  enum COMPONENT_REGISTRY_TYPE {
    COMPONENT_TYPE_TRANSFORM = 0,
    COMPONENT_TYPE_INPUT,
    COMPONENT_TYPE_MOVEMENT,
    COMPONENT_TYPE_SPRITE,
    COMPONENT_TYPE_GRAVITY,
    COMPONENT_TYPE_PARENT,
    COMPONENT_TYPE_MAX      // Ensure this is always the last member of the enum.
  };
}

#endif