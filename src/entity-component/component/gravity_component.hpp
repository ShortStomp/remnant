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
// This component can be added/removed from an entity to add gravitational behavior
// to an object.
// 
//===----------------------------------------------------------------------===///
#ifndef _GRAVITY_COMPONENT_HPP_
#define _GRAVITY_COMPONENT_HPP_
#include "icomponent.hpp"
namespace ec
{
  struct gravity_component :
    public icomponent
  {
    // static members
    static const auto COMPONENT_TYPE = COMPONENT_TYPE_GRAVITY;
    
    // constructors
    gravity_component(void) : icomponent(COMPONENT_TYPE) { }
  };
}
#endif // _GRAVITY_COMPONENT_HPP_