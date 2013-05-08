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
// The base class for every component. A self-containing block of code that can be
// attached / removed from an entity at any time. Each component should be self-containing,
// and (ideally) have no dependence on other components. The component can be implemented as 
// structures. Every component derives from the icomponent interface, so that they may be
// added to the entity’s component collection.
// 
//===----------------------------------------------------------------------===///
#ifndef _ICOMPONENT_HPP_
#define _ICOMPONENT_HPP_
#include "component_registry.hpp"

namespace rem
{
  // forward declarations
  class entity;

  struct icomponent
  {
    // members
    const int   Component_Type;
    entity      *Parent_ptr;

  protected:

    // constructors
    icomponent(const int component_type);
  };
}
#endif // _ICOMPONENT_HPP_ definition