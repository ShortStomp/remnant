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
#include "icomponent.hpp"
namespace rem
{
  struct transform_component :
    public icomponent
  {
    // members
    float Rotation;
    float Position;
    float Scale;

    // constructors
    transform_component(void);
  };
}
#endif // _TRANSFORM_COMPONENT_HPP_