//
// author: Benjamin Adamson and Wesley Kos
// A class that constructs entities. Internally it protects access to _id_counter,
// ensuring all entities are constructed with both a unique and valid id.
#ifndef _ENTITY_FACTORY_HPP
#define _ENTITY_FACTORY_HPP
#include "entity.hpp"

namespace rem
{
  class entity_factory
  {
    // static members
    static unsigned int _id_counter;

  public:

    // constructors
    entity_factory(void);
    
    // methods
    entity get(void) const;
  };
}
#endif // _ENTITY_FACTORY_HPP definition