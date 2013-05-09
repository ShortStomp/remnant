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
// The entity_factory class is the one class that has the ability to construct an
// entity instance. The entity_factory abstracts the work required get a unique id
// for every entity.
//===----------------------------------------------------------------------===//
#ifndef _ENTITY_FACTORY_HPP
#define _ENTITY_FACTORY_HPP
#include "entity.hpp"

namespace ec
{
  class entity_factory
  {
    // static members
    static unsigned int _id_counter;

  public:
    
    // methods
    entity* get(void) const;
  };
}
#endif // _ENTITY_FACTORY_HPP definition