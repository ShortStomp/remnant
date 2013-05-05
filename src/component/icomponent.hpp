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
namespace rem
{
  // forward declarations
  class entity;

  struct icomponent
  {
    // members
    entity *Parent_ptr;

    // constructors
    icomponent(void);
  };
}
#endif